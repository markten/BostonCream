#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

class Map
{
    private:
        int size_x;
        int size_y;
        int mapArray[13][39];
        SDL_Surface* tilesheet;
        SDL_Surface* screen;
        SDL_Rect* clips;

    public:
        Map(int x, int y, SDL_Surface* isprite, SDL_Surface* screen);
        void build_map();
        void show();
};

#endif // MAP_H_INCLUDED
