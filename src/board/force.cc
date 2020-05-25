#include "force.hh"

using namespace player;

namespace board
{
    Force::Force(Team team, ForceType type)
    : team_{team}, type_{type}
    {}

    Team Force::get_team() const
    {
        return team_;
    }

    ForceType Force::get_type() const
    {
        return type_;
    }

    int Force::get_value() const
    {
        switch (type_)
        {
        case ForceType::INFANTRY:
            return static_cast<int>(ForceValue::INFANTRY);
        case ForceType::TANK:
            return static_cast<int>(ForceValue::TANK);
        case ForceType::FIGHTER:
            return static_cast<int>(ForceValue::FIGHTER);
        case ForceType::DESTROYER:
            return static_cast<int>(ForceValue::DESTROYER);
        case ForceType::REGIMENT:
            return static_cast<int>(ForceValue::REGIMENT);
        case ForceType::HEAVY_TANK:
            return static_cast<int>(ForceValue::HEAVY_TANK);
        case ForceType::BOMBER:
            return static_cast<int>(ForceValue::BOMBER);
        case ForceType::CRUISER:
            return static_cast<int>(ForceValue::CRUISER);
        default:
            throw std::invalid_argument("Unknown force");
        }
    }

    int Force::get_nb_moves() const
    {
        switch (type_)
        {
        case ForceType::INFANTRY:
            return static_cast<int>(ForceNbMoves::INFANTRY);
        case ForceType::TANK:
            return static_cast<int>(ForceNbMoves::TANK);
        case ForceType::FIGHTER:
            return static_cast<int>(ForceNbMoves::FIGHTER);
        case ForceType::DESTROYER:
            return static_cast<int>(ForceNbMoves::DESTROYER);
        case ForceType::REGIMENT:
            return static_cast<int>(ForceNbMoves::REGIMENT);
        case ForceType::HEAVY_TANK:
            return static_cast<int>(ForceNbMoves::HEAVY_TANK);
        case ForceType::BOMBER:
            return static_cast<int>(ForceNbMoves::BOMBER);
        case ForceType::CRUISER:
            return static_cast<int>(ForceNbMoves::CRUISER);
        default:
            throw std::invalid_argument("Unknown force");
        }
    }

    TileType Force::get_obstacle_type() const
    {
        switch (type_)
        {
        case ForceType::INFANTRY:
            return TileType::WATER;
        case ForceType::TANK:
            return TileType::WATER;
        case ForceType::FIGHTER:
            return TileType::WATER;
        case ForceType::DESTROYER:
            return TileType::LAND;
        case ForceType::REGIMENT:
            return TileType::WATER;
        case ForceType::HEAVY_TANK:
            return TileType::WATER;
        case ForceType::BOMBER:
            return TileType::WATER;
        case ForceType::CRUISER:
            return TileType::LAND;
        default:
            throw std::invalid_argument("Unknown force");
        }
    }
}
