#include "player.hh"

namespace player
{
    Player::Player(Team team)
    : team_{team}, nb_power_units_{0}
    {}

    Team Player::get_team(void) const
    {
        return team_;
    }

    int Player::get_nb_power_units(void) const
    {
        return nb_power_units_;
    }
}
