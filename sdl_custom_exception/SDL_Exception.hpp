#pragma once
//STL library include
#include <exception>
//SDL include
#include <SDL2/SDL.h>

//Minimal custom exception class for SDL error
//See example usage in main.cpp
struct SDL_Exception : public std::exception
{
    const char* what() const throw()
    {
        return SDL_GetError();
    }
};
