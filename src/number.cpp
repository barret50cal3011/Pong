#include <iostream>

#include "include/Number.hpp"
#include "include/Game.hpp"

int twoPower(unsigned int numb)
{
    if(numb == 0)
        return 1;
    else    
        return 2*twoPower(numb - 1);
    
}

void Number::setPosition(int p_x, int p_y)
{
    digit[0].x = p_x + 10;
    digit[0].y = p_y;
    digit[0].w = 30;
    digit[0].h = 10;

    digit[1].x = p_x;
    digit[1].y = p_y + 10;
    digit[1].w = 10;
    digit[1].h = 30;
    
    digit[2].x = p_x + 40;
    digit[2].y = p_y + 10;
    digit[2].w = 10;
    digit[2].h = 30;
    
    digit[3].x = p_x + 10;
    digit[3].y = p_y + 40;
    digit[3].w = 30;
    digit[3].h = 10;
    
    digit[4].x = p_x;
    digit[4].y = p_y + 50;
    digit[4].w = 10;
    digit[4].h = 30;
    
    digit[5].x = p_x + 40;
    digit[5].y = p_y + 50;
    digit[5].w = 10;
    digit[5].h = 30;
    
    digit[6].x = p_x + 10;
    digit[6].y = p_y + 80;
    digit[6].w = 30;
    digit[6].h = 10;
}

int Number::calculateDigit(unsigned int num)
{
    if(num > 9)
        return 1;

    switch (num)
    {
    case 0:
        number = 0x77;
        break;
    case 1:
        number = 0x12;
        break;
    case 2:
        number = 0x5D;
        break;
    case 3:
        number = 0x6D;
        break;
    case 4:
        number = 0x2E;
        break;
    case 5:
        number = 0x6B;
        break;
    case 6:
        number = 0x7B;
        break;
    case 7:
        number = 0x25;
        break;
    case 8:
        number = 0x7F;
        break;
    case 9:
        number = 0x6F;
        break;
    
    default:
        break;
    }

    return 0;
}

void Number::render()
{
    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
    for(int i = 0; i < 7; i++)
        if((number ^ twoPower(i)) < number)
            SDL_RenderFillRect(Game::renderer, &digit[i]);
}