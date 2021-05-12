#pragma once

#include <SDL2/SDL.h>
#include "Number.hpp"

struct Score
{
    Number score[4];
    int P1, P2;

    Score(int p_x, int p_y);
    void update();
    void render();
};