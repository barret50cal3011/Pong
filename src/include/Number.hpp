#pragma once

#include <SDL2/SDL.h>

struct Number
{
    int number;
    SDL_Rect digit[7];

    void setPosition(int p_x, int p_y);
    int calculateDigit(unsigned int num);
    void render();
};