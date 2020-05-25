#include "tile.hh"

using namespace player;

namespace board
{
    void Tile::set_name(std::string name)
    {
        name_ = name;
    }

    void Tile::set_type(TileType type)
    {
        type_ = type;
    }

    void Tile::set_team(Team team)
    {
        team_ = team;
    }

    int Tile::get_total_value() const
    {
        int total_value = 0;

        for (auto force : forces_)
            total_value += force.get_value();

        return total_value;
    }

    void Tile::pretty_print() const
    {
        switch (team_)
        {
        case Team::GREEN:
            printf("\033[1;32m");
            break;
        case Team::BLUE:
            printf("\033[1;34m");
            break;
        case Team::RED:
            printf("\033[1;31m");
            break;
        case Team::YELLOW:
            printf("\033[1;33m");
            break;
        default:
            printf("\033[0;37m");
            break;
        }

        printf("%s%*s", name_.c_str(), 4 - (int) name_.length(), "");

        /*
        printf("\033[0;30m");

        std::string values = std::to_string(get_total_value());
        printf("(%s)%*s", values.c_str(), 4 - (int) values.length(), "");
        */

        // reset
        printf("\033[0m");
    }

    std::string Tile::get_name() const
    {
        return name_;
    }

    Team Tile::get_team() const
    {
        return team_;
    }

    TileType Tile::get_type() const
    {
        return type_;
    }

    void Tile::add_force(Force force)
    {
        forces_.push_back(force);
    }

    void Tile::print_forces() const
    {
        int nb_infantry = 0;
        int nb_tanks = 0;
        int nb_fighters = 0;
        int nb_destroyers = 0;
        int nb_regiments = 0;
        int nb_heavy_tanks = 0;
        int nb_bombers = 0;
        int nb_cruisers = 0;
        int nb_mega_missiles = 0;

        int total = 0;
        int total_value = 0;

        for (auto force : forces_)
        {
            switch (force.get_type())
            {
            case ForceType::INFANTRY:
                nb_infantry += 1;
                break;
            case ForceType::TANK:
                nb_tanks += 1;
                break;
            case ForceType::FIGHTER:
                nb_fighters += 1;
                break;
            case ForceType::DESTROYER:
                nb_destroyers += 1;
                break;
            case ForceType::REGIMENT:
                nb_regiments += 1;
                break;
            case ForceType::HEAVY_TANK:
                nb_heavy_tanks += 1;
                break;
            case ForceType::BOMBER:
                nb_bombers += 1;
                break;
            case ForceType::CRUISER:
                nb_cruisers += 1;
                break;
            case ForceType::MEGA_MISSILE:
                nb_mega_missiles += 1;
                break;
            }

            total_value += force.get_value();
            total += 1;
        }

        printf("- %d Infantry\n", nb_infantry);
        printf("- %d Tank(s)\n", nb_tanks);
        printf("- %d Figther(s)\n", nb_fighters);
        printf("- %d Destroyer(s)\n", nb_destroyers);
        printf("- %d Regiment(s)\n", nb_regiments);
        printf("- %d Heavy Tank(s)\n", nb_heavy_tanks);
        printf("- %d Bomber(s)\n", nb_bombers);
        printf("- %d Cruiser(s)\n\n", nb_cruisers);
        printf("- %d Mega Missile(s)\n\n", nb_mega_missiles);
        printf("Total of %d forces of value %d.\n", total, total_value);
    }
}
