#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

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

        Character(int x, int y, int width, int height, int tilesheetWidth, int straightVelocity, int crossVelocity, SDL_Surface* isprite, SDL_Surface* screen);
        void set_camera(SDL_Rect* camera);
        void handle_input(SDL_Event event);
        void move();
        void show(SDL_Rect*);
        void collide_box(Character* Object);
        void set_vector(int, int);
};
#endif // CHARACTER_H_INCLUDED
