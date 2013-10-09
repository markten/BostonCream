/*
**  SDL Functions
**  This file contains some rudimentary functions to ease our use of SDL.
**  Most of them are pulled from the LazyFoo Productions tutorials.
**  Functions ease things like adding image resources, drawing sprites and making grids for spritesheets
*/

#include <stdio.h>
#include <string>
#include <sstream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

SDL_Surface *load_image(std::string filename)
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;

    loadedImage = IMG_Load(filename.c_str() );

    if(loadedImage != NULL)
    {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
    }

    if(optimizedImage != NULL)
    {
        // Set color key
        Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0, 0XFF, 0);
        SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
    }
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface (source, clip, destination, &offset);
}

SDL_Rect* create_grid(int size = 0, int tileWidth = 0, int tileHeight = 0, int rowLength = 0)
{
    SDL_Rect* newClip;
    newClip = new SDL_Rect[size];

    for (int index = 0; index < size; index++)
    {
        newClip[index].x = (index%rowLength)*tileWidth;
        newClip[index].y = (index/rowLength)*tileHeight;
        newClip[index].w = tileWidth;
        newClip[index].h = tileHeight;
    }
    return newClip;
}
