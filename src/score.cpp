#include "include/Score.hpp"
#include "include/Number.hpp"
#include "include/Game.hpp"

Score::Score(int p_x, int p_y)
{
    P1 = 0;
    P2 = 0;
    
    score[0].setPosition(p_x, p_y);
    score[1].setPosition(p_x + 60, p_y);
    score[2].setPosition(p_x + 150, p_y);
    score[3].setPosition(p_x + 210, p_y);
}

void Score::update()
{
    score[0].calculateDigit(((P1 % 100) - P1 % 10)/10);
    score[1].calculateDigit(P1 % 10);

    score[2].calculateDigit(((P2 % 100) - P2 % 10)/10);
    score[3].calculateDigit(P2 % 10);
}

void Score::render()
{
    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);

    SDL_Rect rect1;
    rect1.x = 300;
    rect1.y = 30;
    rect1.h = 10;
    rect1.w = 10;

    SDL_Rect rect2;
    rect2.x = 300;
    rect2.y = 70;
    rect2.h = 10;
    rect2.w = 10;

    SDL_RenderFillRect(Game::renderer, &rect1);
    SDL_RenderFillRect(Game::renderer, &rect2);

    for (int i = 0; i < 4; i++)
        score[i].render();
}