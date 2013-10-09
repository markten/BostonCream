/*
** Class - Timer
** This is essentially a copy of the timer class made in the LazyFoo Tutorials.
** All its really used for in this game is regulating framerate.
** It may later be used to time difficulty shifts in levels.
*/


#include <stdio.h>
#include <string>
#include <sstream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Constants.h"

class Timer
{
    private:
        int startTicks;
        int pausedTicks;
        bool paused;
        bool started;

    public:
        Timer();
        void start();
        void stop();
        void pause();
        void unpause();
        int get_ticks();
        bool is_started();
        bool is_paused();
};

Timer::Timer()
{
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Timer::start()
{
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
}

void Timer::stop()
{
    started = false;
    paused = false;
}

int Timer::get_ticks()
{
    if(started==true)
    {
        if(paused==true)
            return pausedTicks;
        else
            return SDL_GetTicks() - startTicks;
    }
    return 0;
}

void Timer::pause()
{
    if((started==true)&&(paused==false))
    {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause()
{
    if(paused==true)
    {
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

bool Timer::is_started()
{
    return started;
}

bool Timer::is_paused()
{
    return paused;
}
