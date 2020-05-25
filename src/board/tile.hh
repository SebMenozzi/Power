#pragma once

#include <iostream>
#include <string>
#include <optional>

#include "force.hh"

using namespace player;

namespace board
{
    enum class TileType : char
    {
        HQ = 'H',
        WATER = 'W',
        ISLAND = 'I',
        LAND = 'L',
        LAND_WATER = 'B'
    };

    class Tile
    {
    public:
        Tile() = default;
        void set_name(std::string name);
        void set_type(TileType type);
        void set_team(Team team);
        void pretty_print() const;
        void print_forces() const;
        void add_force(Force force);

        std::string get_name() const;
        Team get_team() const;
        TileType get_type() const;
        int get_total_value() const;
    private:
        std::string name_;
        TileType type_;
        Team team_;
        std::vector<Force> forces_;
    };
}
