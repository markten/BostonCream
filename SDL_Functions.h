#ifndef SDL_FUNTIONS_H_INCLUDED
#define SDL_FUNTIONS_H_INCLUDED

SDL_Surface *load_image(std::string filename);
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL);
SDL_Rect* create_grid(int size = 0, int tileWidth = 0, int tileHeight = 0, int rowLength = 0);
#endif // SDL_FUNTIONS_H_INCLUDED
