#include <iostream>
#include "SDL_Exception.hpp"

/* Small example on how to use exception for error handling with SDL
 * Using exception to handle SDL error helps avoid the dreaded if-else arrow
 * For reference, this is what the code looks like with regular if-else error checking:
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL init failed with error: " << SDL_GetError() << "\n";
    }
    else
    {
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
        if(!window)
        {
            std::cout << "SDL failed to create window with error: " << SDL_GetError() << "\n";
        }
        else
        {
            std::cout << "Window created, painting surface green!\n";
            SDL_Surface* surface = SDL_GetWindowSurface(window);
            SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x00, 0xFF, 0x00));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(3000);
        }
    }
 * (It gets much worse in larger code base)
 */
int main(int argc, char* argv[])
{
	SDL_Window* window = NULL;
    
    int WINDOW_WIDTH = 800; //Change this to some ridiculous value to see exception happens. 20000 should be enough.
    int WINDOW_HEIGHT = 600;

    try
    {
        if(SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            throw SDL_Exception();
        }
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
        if(!window)
        {
            throw SDL_Exception();
        }
        std::cout << "Window created, painting surface green!\n";
        SDL_Surface* surface = SDL_GetWindowSurface(window);
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x00, 0xFF, 0x00));
        SDL_UpdateWindowSurface(window);
        SDL_Delay(3000);
    }
    catch(SDL_Exception& e)
    {
        std::cout << "SDL failed with exception: " << e.what() << "\n";
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
	return 0;
}
