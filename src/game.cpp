#include <iostream>

#include "include/Game.hpp"
#include "include/Ball.hpp"
#include "include/Player.hpp"
#include "include/Score.hpp"

SDL_Renderer* Game::renderer = NULL;

Game::Game()
{

}

void Game::init(SDL_Window* window)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    ball = new Ball(300, 300);
    player1 = new Player(50, 300);
    player2 = new Player(550, 300);
    ball->p1 =  player1;
    ball->p2 = player2;

    score = new Score(175, 10);
}

bool Game::handleEvents()
{
    SDL_Event evt;
    while(SDL_PollEvent(&evt))
    {
        switch (evt.type)
        {
        case SDL_QUIT:
            return false;
            break;
        case SDL_KEYDOWN:
        {
            int code = evt.key.keysym.scancode;
            //w
            if(code == 26)
                player1->movement = -1;
            
            //s
            if(code == 22)
                player1->movement = 1;

            //arrow up
            if(code == 82)
                player2->movement = -1;

            //arrow down
            if(code == 81)
                player2->movement = 1;

            break;
        }
        case SDL_KEYUP:
        {
            int code = evt.key.keysym.scancode;
            if(code == 26 || code == 22)
                player1->movement = 0;

            if(code == 82 || code == 81)
                player2->movement = 0;
            break;
        }
        }
    }

    return true;
}

void Game::update()
{
    ball->update();
    player1->update();
    player2->update();

    score->P1 = player1->score;
    score->P2 = player2->score;

    score->update();
}

void Game::render()
{
    SDL_Rect background;
    background.x = 0;
    background.y = 0;
    background.h = 600;
    background.w = 600;
    SDL_RenderClear(renderer);

    //background
    SDL_SetRenderDrawColor(renderer, 0,0,0,0);
    SDL_RenderFillRect(renderer, &background);

    //elements
    ball->render();
    player1->render();
    player2->render();

    score->render();

    //std::cout << player1->score << ":" << player2->score << std::endl;

    SDL_RenderPresent(renderer);
}