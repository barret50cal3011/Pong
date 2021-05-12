#include <cmath>
#include <cstdlib>
#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "include/Ball.hpp"
#include "include/Game.hpp"

int randomSing()
{
    int sing = rand()%2;
    if(sing == 0)
        sing = -1;
    
    return sing;
}

Ball::Ball(double p_x, double p_y)
{
    restart(p_x, p_y);    
}

void Ball::restart(double p_x, double p_y)
{
    posx = p_x;
    posy = p_y;

    srand((unsigned int)time(NULL));
    int num = (rand() % 200) - 100;
    
    double rand = num / 100.0;

    if(rand > 0)
    {
        rand *= 0.15;
        rand += 0.8;
    }
    else
    {
        rand *= 0.15;
        rand -= 0.8;
    }

    if(rand == 0)
        rand = 0.5;
    if(rand == 1)
        rand = 0.5;
    velx = rand;

    vely = sqrt(1 - (velx*velx));
    vely *= randomSing();

    velx *= 4;
    vely *= 4;    
}

void Ball::update()
{
    if(posx < 5)
    {
        velx *= -1;

        p2->score++;
        restart(300, 300);
    }

    if(posx > 595)
    {
        velx *= -1;

        p1->score++;
        restart(300, 300);
    }

    if(posy < 5 || posy > 595)
        vely *= -1;

    if(posx <= 60 && posx >= 50)
    {
        if((p1->posy - 75) <= (int)posy && (p1->posy + 75) >= (int)posy)
        {
            velx *= -1;
            
        }
    }

    if(posx >= 540 && posx <= 550)
    {
        if((p2->posy - 75 <= (int)posy) && (p2->posy + 75 >= (int)posy))
            velx *= -1;
    }

    posx += velx;
    posy += vely;

    
}

void Ball::render()
{
    SDL_Rect rect;
    rect.x = (int)posx - 5;
    rect.y = (int)posy - 5;
    rect.h = 10;
    rect.w = 10;

    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(Game::renderer, &rect);
}