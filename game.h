#pragma once

#include <cstdint>

struct coordinates
{
    uint32_t x;
    uint32_t y;
};

enum class User_input
{
    INVALID,
    LEFT = 'a',
    RIGHT = 'd',
    UP = 'w',
    DOWN = 's',
};

bool is_finished(const coordinates &player);

void print_game_state(const coordinates &player);

void execute_move(coordinates &player, const User_input move);

void game();
