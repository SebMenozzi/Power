#pragma once

#include <vector>

#include "board/force.hh"
#include "team.hh"

//using namespace board;

namespace player
{
    class Player
    {
    public:
        Player(Team team);
        Team get_team(void) const;
        int get_nb_power_units(void) const;
    private:
        Team team_;
        int nb_power_units_;
        //std::vector<Force> reserve_forces_;
    };
}
