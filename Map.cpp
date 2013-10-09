#include <stdio.h>
#include <string>
#include <sstream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL_Functions.h"
#include "Timer.h"
#include "Constants.h"

class Map
{
    private:
        int size_x;
        int size_y;
        int mapArray[13][39];
        SDL_Surface* tilesheet;
        SDL_Surface* screen;
        SDL_Rect* clips;
        void build_map();

    public:
        Map(int x, int y, SDL_Surface* isprite, SDL_Surface* screen);
        void show();
};

Map::Map(int x = 13, int y = 39, SDL_Surface* itilesheet = NULL, SDL_Surface* iscreen = NULL)
{
    size_x = x;
    size_y = y;
    tilesheet = itilesheet;
    screen = iscreen;
    clips = create_grid(size_x*size_y, 100, 100, size_x);
    //build_map();
}
/*
void Map::build_map()
{
    bool alternate = false;
    int crap[]={3,9,5,9,5,9,5,9,5,9,5,9,3};

    for(int index_y = 0; index_y < size_y; index_y++)
    {
        for(int index_x = 0; index_x < size_x; index_x++)
        {
                mapArray[index_x][index_y] = 2;
                if(index_x == 0)
                   {
                    if(alternate)
                        mapArray[index_x][index_y] = 10;
                    else
                            mapArray[index_x][index_y] = 6;
                   }
                if(index_x == 12)
                {
                    if(alternate)
                        mapArray[index_x][index_y] = 10;
                    else
                        mapArray[index_x][index_y] = 6;

                    alternate = !alternate;
                }
                if(index_y==size_y)
                {
                    mapArray[index_x][index_y] = crap[index_x];
                }
        }
    }

}*/
void Map::show()
{
    apply_surface(0, 0, tilesheet, screen);
    //apply_surface((index%size_x)*100, (index/size_x)*100, tilesheet, screen, &clips[mapArray[(index%size_x)][(index/size_x)]] );
}
