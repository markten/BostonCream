import pygame
import random
from spritesheet import *

class DonutHole(pygame.sprite.Sprite):
	
    # Movement
    
    # Animation
    frames = []
    current_frame = 0
    
    # Stats
    
    
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        
        if random.randint(0,1):
            self.image = pygame.image.load("sprites/cdhole.png").convert()
        else:
            self.image = pygame.image.load("/sprited/vdhole.png").convert()
        self.image.set_colorkey(GREEN)
        self.rect = self.image.get_rect()
    
class JellyDonut(pygame.sprite.Sprite):
    
    # Movement
    
    # Animation
    frames = []
    current_frame = 0
    
    # Stats
    
    
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load("sprite/donut.png").convert()
        self.image.set_colorkey(GREEN)
        self.rect = self.image.get_rect()
    
class JellySquirt(pygame.sprite.Sprite):
    
    # Movement
    
    # Animation
    frames = []
    current_frame = 0
    
    # Stats
    
    
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        
        self.rect = self.image.get_rect()
    
    
class