#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#include "board/board.hh"
#include "board/tile.hh"

namespace board
{
    class MoveGen
    {
    public:
        static std::vector<int> generate_distances(Board& board, int i, int j);
        static std::vector<int> possible_moves(Board& board, int i, int j, Force force);
        static void print_possible_moves(std::vector<int> moves);
    };
}
