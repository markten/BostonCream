import pygame
from spritesheets import *

class Player(pygame.sprite.Sprite):
	
    # Movement
    velocity = 10
    direction = 0
    
    # Animation
    frames = []
    current_frame = 0
    
    # Stats
    
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        
        
        
class CremeSpot(pygame.sprite.Sprite):
    