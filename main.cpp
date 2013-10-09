#include <stdio.h>
#include <string>
#include <sstream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Constants.h"
#include "Timer.h"
#include "Character.h"
#include "SDL_Functions.h"
#include "Map.h"


// Define surfaces

    SDL_Surface* test              = NULL;
    SDL_Surface* screen             = NULL;
    SDL_Surface* bostonCremeSprite  = NULL;
    SDL_Surface* mapsheet           = NULL;
    SDL_Surface* vDHole             = NULL;
    SDL_Surface* cDHole             = NULL;

// Define Events
    SDL_Event event;

// Set fonts
    //TTF_Font *font = NULL;
    //SDL_Color textColor = {255,255,255};

bool load_files()
{
    // Load/Check all images
    bostonCremeSprite   = load_image("./spritesheets/bostoncreme.png");     if (bostonCremeSprite == NULL)  return false;
    mapsheet            = load_image("./spritesheets/FullMap.png");         if (mapsheet == NULL)           return false;
    test                = load_image("./spritesheets/test.png");            if (test == NULL)               return false;
    vDHole              = load_image("./spritesheets/vdhole.png");          if (vDHole == NULL)             return false;
    cDHole              = load_image("./spritesheets/cdhole.png");          if (cDHole == NULL)             return false;

    // Load Fonts
        //font = TTF_OpenFont("JOKERMAN.ttf", 28);

    return true;
}

void clean_up()
{
    //Free image resources
        SDL_FreeSurface(bostonCremeSprite);
        SDL_FreeSurface(mapsheet);
        SDL_FreeSurface(test);
        SDL_FreeSurface(vDHole);
        SDL_FreeSurface(cDHole);
        SDL_FreeSurface(screen);
    //TTF_CloseFont(font);

    // Quit
    TTF_Quit();
    SDL_Quit();
}

bool init()
{
    if (SDL_Init (SDL_INIT_EVERYTHING) == -1)
        return false;

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    if(screen == NULL)
        return false;

    if (TTF_Init() == -1)
        return false;

    SDL_WM_SetCaption("Boston Creme", NULL);

    return true;
}

int main ( int argc, char * args[] )
{
    // Variable declarations
        bool quit = false;

    // Framerate regulation
        int frame = 0;
        Timer fps;

    // Initialization
        if (init() == false)
            return 1;
        if (load_files() == false)
            return 1;

    //The camera
        SDL_Rect* camera = NULL;
        camera = new SDL_Rect;
            camera->x = 0;
            camera->y = 0;
            camera->w = SCREEN_WIDTH;
            camera->h = SCREEN_HEIGHT;

    // Make Characters
        Character myDonut(400, 400, BOSTON_WIDTH, BOSTON_HEIGHT, 6, BOSTON_VELOCITY, BOSTON_X_VELOCITY, bostonCremeSprite, screen);
        Character myEclair(400, 800, ECLAIR_WIDTH, ECLAIR_HEIGHT, 1, 0, 0, test, screen);
        Character anEnemy(200, 200, DHOLE_WIDTH, DHOLE_HEIGHT, 4, DHOLE_VELOCITY, DHOLE_X_VELOCITY, vDHole, screen);
        anEnemy.set_vector(2,-1);

    while(quit == false)
    {
        // Start fps timer
            fps.start();

        // Handle keystrokes
            while( SDL_PollEvent( &event ) )
                {
                    myDonut.handle_input(event);
                    if( event.type == SDL_QUIT )
                        quit = true;
                }

        // Update character positions
            myDonut.collide_box(&myEclair);
            myDonut.move();
            anEnemy.move();
            myDonut.set_camera(camera);

        // Draw the screen
            apply_surface( 0, 0, mapsheet, screen, camera);
            myDonut.show(camera);
            myEclair.show(camera);
            anEnemy.show(camera);

        // Update screen and implement fps delays
            if (SDL_Flip (screen) == -1)
                return 1;
            frame++;
            if(fps.get_ticks() < (1000/FRAMES_PER_SECOND))
                SDL_Delay((1000/FRAMES_PER_SECOND)-fps.get_ticks());
    }
    // Free Dynamic Mem
        delete camera;
    clean_up();
    return 0;
}
