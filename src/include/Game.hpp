#pragma once

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Ball.hpp"
#include "Player.hpp"
#include "Score.hpp"

class Game
{
public:

    Game();
    ~Game();

    void init(SDL_Window* window);
    bool handleEvents();
    void update();
    void render();

    static SDL_Renderer* renderer;

private:

    Ball* ball;
    Player* player1;
    Player* player2;

    Score* score;
};