/*
**  Class - Character
**  This class is the basis for all objects that will move on the map.
**  It has functions to move, collide and draw the character it represents
**  This class also handles user input for tha main character
**
*/

#include <stdio.h>
#include <string>
#include <sstream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL_Functions.h"
#include "Timer.h"
#include "Constants.h"

class Character
{
    private:
        int x, y;
        int velocity;
        int currentFrame;
        bool isMovingForwards;
        bool isMovingBackwards;
        bool collided;
        int straightVelocity;
        int crossVelocity;
        int width;
        int height;
        int direction;
        int tilesheetWidth;
        SDL_Surface* sprite;
        SDL_Surface* screen;
        SDL_Rect* clip;

    public:

        Character(int newX, int newY, int newWidth, int newHeight, int newTilesheetWidth, int newStraightVelocity, int newCrossVelocity, SDL_Surface* newSprite, SDL_Surface* newScreen);
        void set_camera(SDL_Rect* camera);
        void handle_input(SDL_Event event);
        void move();
        void show(SDL_Rect*);
        void collide_box(Character* Object);
        void set_vector(int, int);
};


Character::Character(
    int newX                    = 0,
    int newY                    = 0,
    int newWidth                = 10,
    int newHeight               = 10,
    int newTilesheetWidth       = 0,
    int newStraightVelocity     = 0,
    int newCrossVelocity        = 0,
    SDL_Surface* newSprite      = NULL,
    SDL_Surface* newScreen      = NULL)
{
    x                   = newX;
    y                   = newY;
    width               = newWidth;
    height              = newHeight;
    tilesheetWidth      = newTilesheetWidth;
    velocity            = 0;
    direction           = 0;
    currentFrame        = 0;
    straightVelocity    = newStraightVelocity;
    crossVelocity       = newCrossVelocity;
    sprite              = newSprite;
    screen              = newScreen;
    isMovingForwards    = isMovingBackwards = collided = false;

    if(tilesheetWidth > 0 )
        clip = create_grid(tilesheetWidth*8, width, height, tilesheetWidth);
}

void Character::handle_input(SDL_Event event)
{
    if(event.type==SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP:   velocity = -1;   isMovingForwards = true;        break;
            case SDLK_DOWN: velocity = 1;  isMovingBackwards = true;       break;
            case SDLK_LEFT: direction--;    if(direction<0) direction=7;    break;
            case SDLK_RIGHT:direction++;    if(direction>7) direction=0;    break;
            default: break;
        }
    }
    else if( event.type == SDL_KEYUP )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_UP:   velocity = 0;   isMovingForwards = false;   break;
            case SDLK_DOWN: velocity = 0;   isMovingBackwards = false;  break;
            default: break;
        }
    }
}

void Character::move()
{
    if(!collided)
        {
            switch(direction)
            {
                case 0: y -= (velocity*(-straightVelocity));                                    break;
                case 1: y -= (velocity*(-crossVelocity));   x -= (velocity*crossVelocity);      break;
                case 2: x -= (velocity*straightVelocity);                                       break;
                case 3: y -= (velocity*crossVelocity);      x -= (velocity*crossVelocity);      break;
                case 4: y -= (velocity*straightVelocity);                                       break;
                case 5: y -= (velocity*crossVelocity);      x -= (velocity*(-crossVelocity));   break;
                case 6: x -= (velocity*(-straightVelocity));                                    break;
                case 7: y -= (velocity*(-crossVelocity));   x -= (velocity*(-crossVelocity));   break;
                default: break;
            }
        }

    if(direction%2)
        {
            if(x < 0 + MAP_TILE_SIZE)
                x += crossVelocity;
            if(x + width > LEVEL_WIDTH - MAP_TILE_SIZE)
                x -= crossVelocity;
            if(y < 0)
                y += crossVelocity;
            if(y + height > LEVEL_HEIGHT - MAP_TILE_SIZE)
                y -= crossVelocity;
        }
    else
        {
            if(x < 0 + MAP_TILE_SIZE)
                x += straightVelocity;
            if(x + width > LEVEL_WIDTH - MAP_TILE_SIZE)
                x -= straightVelocity;
            if(y < 0)
                y += straightVelocity;
            if(y + height > LEVEL_HEIGHT - MAP_TILE_SIZE)
                y -= straightVelocity;
        }
    // reset collision flag
        collided = false;
}

void Character::set_vector(int newDirection, int newVelocity)
{
    direction = newDirection;
    velocity = newVelocity;
    isMovingForwards = true;
}

void Character::show(SDL_Rect* camera)
{
    apply_surface(x - camera->x, y - camera->y, sprite, screen, &clip[(tilesheetWidth*direction)+currentFrame] );

    if(isMovingBackwards)
        {
            currentFrame--;
            if(currentFrame < 0)
                currentFrame = tilesheetWidth - 1;
        }
    if(isMovingForwards)
        {
            currentFrame++;
            if(currentFrame > tilesheetWidth-1)
                currentFrame = 0;
        }
}

void Character::set_camera(SDL_Rect* camera)
{
    camera->y = ( this->y - (SCREEN_HEIGHT / 2));

    if( camera->y < 0)
        camera->y = 0;

    if( camera->y > LEVEL_HEIGHT - SCREEN_HEIGHT )
        camera->y = LEVEL_HEIGHT - SCREEN_HEIGHT;
}

void Character::collide_box(Character* Object)
{
    // Move object coordinates
        switch(direction)
            {
                case 0: y += (velocity*(-straightVelocity));                                    break;
                case 1: y += (velocity*(-crossVelocity));   x += (velocity*crossVelocity);      break;
                case 2: x += (velocity*straightVelocity);                                       break;
                case 3: y += (velocity*crossVelocity);      x += (velocity*crossVelocity);      break;
                case 4: y += (velocity*straightVelocity);                                       break;
                case 5: y += (velocity*crossVelocity);      x += (velocity*(-crossVelocity));   break;
                case 6: x += (velocity*(-straightVelocity));                                    break;
                case 7: y += (velocity*(-crossVelocity));   x += (velocity*(-crossVelocity));   break;
                default: break;
            }

    // Create collision rectangles
        int leftA, leftB;
        int rightA, rightB;
        int topA, topB;
        int bottomA, bottomB;

        leftA   = x;
        rightA  = x + width;
        topA    = y;
        bottomA = y + height;

        leftB   = Object->x;
        rightB  = Object->x + Object->width;
        topB    = Object->y;
        bottomB = Object->y + Object->height;

    // Collide recatangles
        if( bottomA <= topB )
            collided = true;
        else if( topA >= bottomB )
            collided = true;
        else if( rightA <= leftB )
            collided = true;
        else if( leftA >= rightB )
            collided = true;
        else
            collided = false;
}
