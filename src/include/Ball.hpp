#pragma once

#include <SDL2/SDL.h>

#include "Player.hpp"

struct Ball
{
    double posx, posy;
    double velx, vely;

    Player* p1;
    Player* p2;

    Ball(double p_x, double p_y);
    void restart(double p_x, double p_y);
    void update();
    void render();
};