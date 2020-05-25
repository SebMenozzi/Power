#pragma once

#include "player/team.hh"
#include "player/player.hh"
#include "board/tile.hh"

using namespace player;

namespace board
{
    enum class NbForcesInit : int
    {
        INFANTRY = 2,
        TANK = 2,
        FIGHTER = 2,
        DESTROYER = 2,
        REGIMENT = 0,
        HEAVY_TANK = 0,
        BOMBER = 0,
        CRUISER = 0,
        MEGA_MISSILE = 0
    };

    enum class ForceType
    {
        INFANTRY = 'I',
        TANK = 'T',
        FIGHTER = 'F',
        DESTROYER = 'D',
        REGIMENT = 'R',
        HEAVY_TANK = 'H',
        BOMBER = 'B',
        CRUISER = 'C',
        MEGA_MISSILE = 'M'
    };

    enum class ForceValue : int
    {
        INFANTRY = 2,
        TANK = 3,
        FIGHTER = 5,
        DESTROYER = 10,
        REGIMENT = 20,
        HEAVY_TANK = 30,
        BOMBER = 25,
        CRUISER = 50,
        MEGA_MISSILE = 100
    };

    enum class ForceNbMoves : int
    {
        INFANTRY = 2,
        TANK = 3,
        FIGHTER = 5,
        DESTROYER = 1,
        REGIMENT = 2,
        HEAVY_TANK = 3,
        BOMBER = 5,
        CRUISER = 1
    };

    class Force
    {
    public:
        Force(Team team, ForceType type);

        Team get_team() const;
        ForceType get_type() const;
        int get_value() const;
        int get_nb_moves() const;
        TileType get_obstacle_type() const;
    private:
        Team team_;
        ForceType type_;
    };
}
