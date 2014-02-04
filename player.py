import pygame
from constants import *
from spritesheet import *
from math import pi, cos, sin

class Player(pygame.sprite.Sprite):
	
    # Movement
    velocity = 20
    direction = 0
    moving = 0
    
    # Animation
    frames = []
    current_frame = 0
    
    # Stats
    
    def __init__(self, x, y):
        pygame.sprite.Sprite.__init__(self)
        sprite_sheet = Spritesheet("sprites/bostoncream.png")
        self.frames = sprite_sheet.get_frames(PLAYER_SPRITE_X_SIZE, PLAYER_SPRITE_Y_SIZE)
        self.image = self.frames[0]
        self.rect = self.image.get_rect()
        
        self.rect.centerx = x
        self.rect.centery = y
        
    def turn_right(self):
        if self.direction < 7:
            self.direction += 1
        else:
            self.direction = 0
    
    def turn_left(self):
        if self.direction > 0:
            self.direction -= 1
        else:
            self.direction = 7
            
    def update(self):
        # update position
        self.rect.centerx += (self.moving * self.velocity * cos(THETA[self.direction]))
        self.rect.centery -= (self.moving * self.velocity * sin(THETA[self.direction]))
        
        # update animation
        if self.moving != 0:
            if self.current_frame < 5:
                self.current_frame += 1
            else:
                self.current_frame = 0
            self.image = self.frames[self.current_frame + (self.direction * 6)]
        
"""class CremeSpot(pygame.sprite.Sprite):
    
    def __init__(self):
            pygame.sprite.Sprite.__init__(self)
            sprite_sheet = Spritesheet("sprites/
            self.rect = self.image.get_rect()
"""

def drop_cream_trail():
    pass