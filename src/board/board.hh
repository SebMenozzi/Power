#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <optional>

#include "board/tile.hh"

using namespace player;

namespace board
{
    using opt_tile_t = std::optional<Tile*>;

    class Board
    {
    public:
        Board(int level);
        void pretty_print(void) const;
        void print_forces(int i, int j) const;

        Tile* get_tile(int i, int j) const;
        void set_tile(int i, int j, std::string name, TileType type, Team team);
        opt_tile_t get_tile_by_name(std::string name);
        opt_tile_t get_headquarter_tile(player::Team team);
        std::vector<Tile*> get_tiles(void) const;
        int get_size(void) const;
        void clear(void);
        bool is_bound(int i, int j) const;
    private:
        void setup_headquarters(void);
        void setup_waters(void);
        void setup_countries(void);
        void setup_islands(void);
        void setup_initial_forces(void);

        std::vector<Tile*> tiles_;
        int level_;
        int size_;
    };
}
