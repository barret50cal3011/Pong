#pragma once

#include <SDL2/SDL.h>

struct Player
{
    int posx;
    int posy;
    int score;
    int movement;

    Player(int p_x, int p_y);
    void update();
    void render();
};