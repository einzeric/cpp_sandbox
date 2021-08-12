/**
 * A simple experiment to see whether SDL_Texture can be saved to file, then loaded back directly from file.
 * Short answer: No.
 * When a texture is created, it is bound to a rendering context, which is unique for each session.
 * Data contained in SDL_Texture seems to include data on the rendering context as well.
 * Furthermore, there is no way to programmatically know the size of a block of SDL_Texture, making it
 * impossible to correctly write the data to a file.
 * 
 * The result of this experiment is as follow:
 * - Crash immediately upon calling SDL_RenderCopy if the texture is loaded from a different session.
 * - If loaded from the same session, texture is displayed correctly (at least I see nothing unusual),
 * but program still crash on exit.
 * 
 * Not really useful for any practical application, but could be an interesting way to encrypt messages,
 * provided the rendering context used to create the texture can be stored and recreated, which is not
 * possible at the moment. This warrant further experimenting.
 */

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using runtime_err = std::runtime_error;

void saveTextureToFile(SDL_Texture* tex)
{
    std::ofstream file("texture.tex", std::ios::binary);
    if(file.is_open())
    {
        file.write(reinterpret_cast<char*>(tex), 4096);
    }
    file.close();
}

void loadTextureFromFile(SDL_Texture* tex)
{
    std::ifstream file("texture.tex", std::ios::binary);
    if(file.is_open())
    {
        file.read(reinterpret_cast<char*>(tex), 4096);
    }
    file.close();
}

int main(int argc, char **argv)
{
    SDL_Window* mWindow = nullptr;
    SDL_Renderer* mRenderer =  nullptr;
    try
    {
        if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            throw runtime_err("Failed to init SDL with error: ");
        }
        //Create the window
        mWindow = SDL_CreateWindow("test window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600,SDL_WINDOW_SHOWN);
        if(!mWindow)
        {
            throw runtime_err("Window creation failed with error: ");
        }
        //Create the renderer
        mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
        if(!mRenderer)
        {
            throw runtime_err("Failed to create renderer with error: ");
        }
        //Init PNG loading
        int imgInitFlag = IMG_INIT_PNG;
        if(!(IMG_Init(imgInitFlag) & imgInitFlag))
        {
            throw runtime_err("Failed to init image loading with error: ");
        }
        //Load an image
        SDL_Surface* loadedImg = IMG_Load("./../assets/image.png");
        if(!loadedImg)
        {
            throw runtime_err("Failed to load image.");
        }
        SDL_Texture* originalTex = SDL_CreateTextureFromSurface(mRenderer, loadedImg);
        SDL_FreeSurface(loadedImg);
        saveTextureToFile(originalTex);
        
        SDL_Texture* texFromFile;
        loadTextureFromFile(texFromFile);
        
        //Rendering
        SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 0);
        SDL_RenderClear(mRenderer);
        
        SDL_Rect original = {0,0,400,300};
        SDL_Rect loaded = {400,0,400,300};
        SDL_RenderCopy(mRenderer, originalTex, NULL, &original);
        SDL_RenderCopy(mRenderer, texFromFile, NULL, &loaded);
        SDL_RenderPresent(mRenderer);
        SDL_DestroyTexture(originalTex);
        SDL_DestroyTexture(texFromFile);
    }
    catch(runtime_err& e)
    {
        std::cout << e.what() << SDL_GetError() << "\n";
    }
    
    SDL_Delay(3000);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
    std::cout << "Done\n";
        
	return 0;
}
