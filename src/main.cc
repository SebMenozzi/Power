#include <iostream>

#include "board/board.hh"
#include "board/move_gen.hh"
#include "player/player.hh"

int main(void)
{
    auto board = board::Board(3);

    /*
    auto green_player = Player(Team::GREEN);
    auto blue_player = Player(Team::BLUE);
    auto red_player = Player(Team::RED);
    auto yellow_player = Player(Team::YELLOW);
    */

    auto moves = board::MoveGen::possible_moves(board, 4, 0, 2);
    board::MoveGen::print_possible_moves(moves);

    board.pretty_print();
    board.clear();

    return 0;
}
