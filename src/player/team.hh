#pragma once

#include <array>

namespace player
{
    enum class Team
    {
        BLUE = 'B',
        GREEN = 'G',
        RED = 'R',
        YELLOW = 'Y',
        NONE = 'N'
    };

    constexpr std::array<Team, 5> team_array
    {
        Team::BLUE,
        Team::GREEN,
        Team::RED,
        Team::YELLOW,
        Team::NONE
    };
}
