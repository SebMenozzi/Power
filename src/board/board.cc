#include "board.hh"

namespace board
{
    Board::Board(int level)
    : level_{level}, size_{1 + level + 1 + level + 1}
    {
        tiles_.reserve(size_ * size_);

        for (int i = 0; i < size_ * size_; ++i)
            tiles_.push_back(new Tile());

        setup_headquarters();
        setup_waters();
        setup_countries();
        setup_islands();

        setup_initial_forces();
    }

    void Board::set_tile(int i, int j, std::string name, TileType type, Team team)
    {
        auto tile = tiles_.at(size_ * i + j);

        tile->set_name(name);
        tile->set_type(type);
        tile->set_team(team);
    }

    Tile* Board::get_tile(int i, int j) const
    {
        return tiles_.at(size_ * i + j);
    }

    opt_tile_t Board::get_tile_by_name(std::string name)
    {
        for (auto tile : tiles_)
            if (tile->get_name() == name)
                return opt_tile_t(tile);

        return std::nullopt;
    }

    opt_tile_t Board::get_headquarter_tile(player::Team team)
    {
        for (auto tile : tiles_)
            if (tile->get_team() == team && tile->get_type() == TileType::HQ)
                return opt_tile_t(tile);

        return std::nullopt;
    }

    void Board::pretty_print() const
    {
        int i = 1;
        for (auto tile : tiles_)
        {
            tile->pretty_print();
            if (i % size_ == 0)
                printf("\n\n");
            ++i;
        }

        printf("\n");
    }

    void Board::print_forces(int i, int j) const
    {
        auto tile = get_tile(i, j);
        tile->print_forces();
    }

    void Board::setup_headquarters(void)
    {
        // Blue headquarter
        set_tile(0, size_ - 1, "BHQ", TileType::HQ, Team:: BLUE);

        // Green headquarter
        set_tile(0, 0, "GHQ", TileType::HQ, Team::GREEN);

        // Red headquarter
        set_tile(size_ - 1, 0, "RHQ", TileType::HQ, Team::RED);

        // Yellow headquarter
        set_tile(size_ - 1, size_ - 1, "YHQ", TileType::HQ, Team::YELLOW);
    }

    void Board::setup_waters()
    {
        // S6
        for (int j = 1; j <= level_; ++j)
            set_tile(0, j, "S6", TileType::WATER, Team::NONE);

        // S7
        for (int j = 1 + level_ + 1; j <= size_ - 2; ++j)
            set_tile(0, j, "S7", TileType::WATER, Team::NONE);

        // S4
        for (int j = 1; j <= level_; ++j)
            set_tile(1 + level_, j, "S4", TileType::WATER, Team::NONE);

        // S2
        for (int j = 1 + level_ + 1; j <= size_ - 2; ++j)
            set_tile(1 + level_, j, "S2", TileType::WATER, Team::NONE);

        // S11
        for (int j = 1; j <= level_; ++j)
            set_tile(size_ - 1, j, "S11", TileType::WATER, Team::NONE);

        // S10
        for (int j = 1 + level_ + 1; j <= size_ - 2; ++j)
            set_tile(size_ - 1, j, "S10", TileType::WATER, Team::NONE);

        /**********/

        // S5
        for (int i = 1; i <= level_; ++i)
            set_tile(i, 0, "S5", TileType::WATER, Team::NONE);

        // S12
        for (int i = 1 + level_ + 1; i <= size_ - 2; ++i)
            set_tile(i, 0, "S12", TileType::WATER, Team::NONE);

        // S1
        for (int i = 1; i <= level_; ++i)
            set_tile(i, 1 + level_, "S1", TileType::WATER, Team::NONE);

        // S3
        for (int i = 1 + level_ + 1; i <= size_ - 2; ++i)
            set_tile(i, 1 + level_, "S3", TileType::WATER, Team::NONE);

        // S8
        for (int i = 1; i <= level_; ++i)
            set_tile(i, size_ - 1, "S8", TileType::WATER, Team::NONE);

        // S9
        for (int i = 1 + level_ + 1; i <= size_ - 2; ++i)
            set_tile(i, size_ - 1, "S9", TileType::WATER, Team::NONE);
    }

    void Board::setup_countries()
    {
        int c;

        // Green country
        c = 0;
        for (int i = 1; i <= level_; ++i)
            for (int j = 1; j <= level_; ++j)
                set_tile(i, j, "G" + std::to_string(++c), TileType::LAND, Team::GREEN);

        // Blue country
        c = 0;
        for (int i = 1; i <= level_; ++i)
            for (int j = 1 + level_ + 1; j <= size_ - 2; ++j)
                set_tile(i, j, "B" + std::to_string(++c), TileType::LAND, Team::BLUE);

        // Red country
        c = 0;
        for (int i = 1 + level_ + 1; i <= size_ - 2; ++i)
            for (int j = 1; j <= level_; ++j)
                set_tile(i, j, "R" + std::to_string(++c), TileType::LAND, Team::RED);

        // Yellow country
        c = 0;
        for (int i = 1 + level_ + 1; i <= size_ - 2; ++i)
            for (int j = 1 + level_ + 1; j <= size_ - 2; ++j)
                set_tile(i, j, "Y" + std::to_string(++c), TileType::LAND, Team::YELLOW);
    }

    void Board::setup_islands()
    {
        // N
        set_tile(0, 1 + level_, "N", TileType::ISLAND, Team::NONE);

        // S
        set_tile(size_ - 1, 1 + level_, "S", TileType::ISLAND, Team::NONE);

        // E
        set_tile(1 + level_, 0, "E", TileType::ISLAND, Team::NONE);

        // W
        set_tile(1 + level_, size_ - 1, "W", TileType::ISLAND, Team::NONE);

        // X
        set_tile(1 + level_, 1 + level_, "X", TileType::ISLAND, Team::NONE);
    }

    void Board::setup_initial_forces()
    {
        for (auto team : team_array)
        {
            auto tile_opt = get_headquarter_tile(team);

            if (tile_opt == std::nullopt)
                continue;

            auto tile = tile_opt.value();

            for (int i = 1; i <= static_cast<int>(NbForcesInit::INFANTRY); ++i)
                tile->add_force(Force(team, ForceType::INFANTRY));

            for (int i = 1; i <= static_cast<int>(NbForcesInit::TANK); ++i)
                tile->add_force(Force(team, ForceType::TANK));

            for (int i = 1; i <= static_cast<int>(NbForcesInit::FIGHTER); ++i)
                tile->add_force(Force(team, ForceType::FIGHTER));

            for (int i = 1; i <= static_cast<int>(NbForcesInit::DESTROYER); ++i)
                tile->add_force(Force(team, ForceType::DESTROYER));
        }
    }

    std::vector<Tile*> Board::get_tiles() const
    {
        return tiles_;
    }

    int Board::get_size() const
    {
        return size_;
    }

    void Board::clear()
    {
        for (auto tile : tiles_)
            delete tile;

        tiles_.clear();
    }

    bool Board::is_bound(int i, int j) const
    {
        return (i >= 0 && i < size_ && j >= 0 && j < size_);
    }
}
