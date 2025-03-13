#include <cstdint>
#include <iostream>

#include "game.h"

namespace
{
constexpr static auto LEN_Y = 5U;
constexpr static auto LEN_X = 5U;
constexpr static auto START = coordinates{.x = 0U, .y = 0U};
constexpr static auto GOAL = coordinates{.x = LEN_X -1, .y = LEN_Y -1};
}; // namespace


bool is_finished(const coordinates &player)
{
    return player.x == GOAL.x && player.y == GOAL.y;
}

void print_game_state(const coordinates &player)
{
for (std::uint32_t i = START.y; i < LEN_Y; i++){
    for (std::uint32_t j = START.x; j < LEN_X; j++)
    {
        if (i == player.y && j == player.x)
        {
            std::cout << 'P';
        }
        else if ((i == GOAL.y && j == GOAL.x) || (i == START.y && j == START.x))
        {
            std::cout << '|';
        }
        else
        {
            std::cout << '.';
        }
    }
    std::cout << '\n';
}
std::cout << '\n';
}

void execute_move(coordinates &player, const User_input move)
{
switch (move){
    case User_input::LEFT:
        if (player.x > 0)
            player.x--;
        break;
    case User_input::RIGHT:
        if (player.x < LEN_X - 1)
            player.x++;
        break;
    case User_input::UP:
        if (player.y > 0)
            player.y--;
        break;
    case User_input::DOWN:
        if (player.y < LEN_Y - 1)
            player.y++;
        break;
    default:
        std::cout << "Unrecognized move!\n";
        break;
    }
}

void game()
{
    auto player = coordinates{.x = START.x, .y = START.y};
    char move;

    while (true)
    {
        std::system("clear");
        if (is_finished(player))
        {
            break;
        }

        print_game_state(player);
        std::cin >> move;
        execute_move(player, User_input(move));
    }
}
