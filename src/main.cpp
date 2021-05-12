#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>

#include "include/Game.hpp"

int main(int args, char* argv[])
{
    //init sdl (video only)
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL was not initializad" << std::endl;
        return 1;
    }

    //mk window
    SDL_Window* window = SDL_CreateWindow("Pong", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_OPENGL);

    if(!window)
    {
        std::cout << "no window created" << std::endl;
        return 2;
    }

    Game* game = new Game();
    game->init(window);

    const int FPS = 60;
    const int frameDel = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    //game loop
    bool running = true;
    while(running)
    {
        frameStart = SDL_GetTicks();

        running = game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDel > frameTime)
            SDL_Delay(frameDel - frameTime);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}