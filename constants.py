import pygame
from math import pi

### Render options
WINDOW_X_SIZE   = 800
WINDOW_Y_SIZE   = 600
WINDOW_SIZE     = (WINDOW_X_SIZE, WINDOW_Y_SIZE)
MAP_X_SIZE      = 800
MAP_Y_SIZE      = 600

FPS = 20

START_X = 100
START_Y = 100

### Color Constants
BLACK   = (   0,   0,   0)
WHITE   = ( 255, 255, 255)
RED     = ( 255,   0,   0)
GREEN   = (   0, 255,   0)
BLUE    = (   0,   0, 255)
AZURE   = (   0, 127, 255)
GRAY    = ( 192, 192, 192)

### Timer Event Constants
BLINK_TIMER = pygame.USEREVENT+1

### Spritesheet dimensions
PLAYER_SPRITE_X_SIZE    = 60
PLAYER_SPRITE_Y_SIZE    = 60

DHOLE_SPRITE_X_SIZE     = 30
DHOLE_SPRITE_Y_SIZE     = 30

JDONUT_SPRITE_X_SIZE    = 60
JDONUT_SPRITE_Y_SIZE    = 60

JSQUIRT_SPRITE_X_SIZE   = 30
JSQUIRT_SPRITE_Y_SIZE   = 30

DONUT_SPRITE_X_SIZE     = 100
DONUT_SPRITE_Y_SIZE     = 100

EXPLOSION_SPRITE_X_SIZE = 60
EXPLOSION_SPRITE_Y_SIZE = 60

# Movement constants

THETA = ((pi/2), (pi/4), 0, (-pi/4), (-pi/2), ((-3*pi)/4), pi, ((3*pi)/4))