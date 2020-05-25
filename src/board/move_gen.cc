#include "move_gen.hh"

namespace board
{
    std::vector<int> MoveGen::generate_distances(Board& board, int i, int j)
    {
        int size = board.get_size();

        // make initial distance of all vertex -1
        std::vector<int> distances;

        for (int i = 0; i < size * size; ++i)
            distances.push_back(-1);

        int pos = board.get_size() * i + j;

        // distance from itself to 0
        distances[pos] = 0;

        // Create a queue for BFS
        std::queue<std::pair<int, int>> queue;

        auto node = std::make_pair(i, j);
        queue.push(node);

        int row_neighbors[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
        int col_neighbors[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

        while (!queue.empty())
        {
            node = queue.front();
            queue.pop();

            i = node.first;
            j = node.second;
            pos = board.get_size() * i + j;

            for (int k = 0; k < 8; ++k)
            {
                int ni = i + row_neighbors[k];
                int nj = j + col_neighbors[k];
                int new_pos = board.get_size() * ni + nj;

                if (board.is_bound(ni, nj)
                    && (distances[new_pos] < 0 || distances[new_pos] > distances[pos] + 1))
                {
                    distances[new_pos] = distances[pos] + 1;
                    queue.push(std::make_pair(ni, nj));
                }
            }
        }

        return distances;
    }

    std::vector<int> MoveGen::possible_moves(Board& board, int i, int j, Force force)
    {
        std::vector<int> distances = generate_distances(board, i, j);

        int size = std::sqrt(distances.size());

        // reset max distance
        for (int k = 0; k < size; ++k)
        {
            for (int l = 0; l < size; ++l)
            {
                int pos = size * k + l;
                if (distances[pos] > force.get_nb_moves() ||
                    board.get_tile(k, l)->get_type() == force.get_obstacle_type())
                    distances[pos] = -1;
            }
        }

        return distances;
    }

    void MoveGen::print_possible_moves(std::vector<int> moves)
    {
        int size = std::sqrt(moves.size());

        for (int k = 0; k < size; ++k)
        {
            for (int l = 0; l < size; ++l)
            {
                auto value = std::to_string(moves[size * k + l]);

                if (value != "-1")
                    printf("\033[1;32m");
                else
                    printf("\033[1;31m");

                printf("%s%*s", value.c_str(), 3 - (int) value.length(), "");

                // reset
                printf("\033[0m");
            }
            printf("\n");
        }
        printf("\n");
    }
}
