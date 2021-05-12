#include "include/Player.hpp"
#include "include/Game.hpp"

Player::Player(int p_x, int p_y)
{
    posx = p_x;
    posy = p_y;
    score = 0;
    movement = 0;
}

void Player::update()
{
    if(posy == 75 && movement == -1)
        movement = 0;

    if(posy == 525 && movement == 1)
        movement = 0;
        
    posy += movement * 3;
}

void Player::render()
{
    SDL_Rect rect;
    rect.x = posx - 10;
    rect.y = posy - 75;
    rect.h = 150;
    rect.w = 20;

    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(Game::renderer, &rect);
}