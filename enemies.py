import pygame
import random
from spritesheet import *

class DonutHole(pygame.sprite.Sprite):
	
    # Movement
    direction = 0
    
    # Animation
    frames = []
    current_frame = 0
    
    # Stats
    
    
    def __init__(self, x, y):
        
        pygame.sprite.Sprite.__init__(self)
        
        if random.randint(0,1):
            sprite_sheet = Spritesheet("sprites/cdhole.png")
        else:
            sprite_sheet = Spritesheet("sprites/vdhole.png")
        frames = sprite_sheet.get_frames(DHOLE_SPRITE_X_SIZE, DHOLE_SPRITE_Y_SIZE)
        self.image = frames[0]
        self.rect = self.image.get_rect()
        
        self.rect.centerx = x
        self.rect.centery = y
        
class PlainDonut(pygame.sprite.Sprite):
    
    # Movement
    
    
    # Animation
    frames = []
    current_frame = 0
    
    
    # Stats
    
    
    def __init__(self, x, y):
        
        pygame.sprite.Sprite.__init__(self)
        
        sprite_sheet = Spritesheet("sprites/donut.png")
        frames = sprite_sheet.get_frames(DONUT_SPRITE_X_SIZE, DONUT_SPRITE_Y_SIZE)
        self.image = frames[0]
        self.rect = self.image.get_rect()
        
        self.rect.centerx = x
        self.rect.centery = y
    
class JellyDonut(pygame.sprite.Sprite):
    
    # Movement
    direction = 0
    
    # Animation
    frames = []
    current_frame = 0
    
    # Stats
    
    
    def __init__(self, x, y):
        
        pygame.sprite.Sprite.__init__(self)
        
        sprite_sheet = Spritesheet("sprites/jdonut.png")
        frames = sprite_sheet.get_frames(JDONUT_SPRITE_X_SIZE, JDONUT_SPRITE_Y_SIZE)
        self.image = frames[0]
        self.rect = self.image.get_rect()
        
        self.rect.centerx = x
        self.rect.centery = y
    
class JellySquirt(pygame.sprite.Sprite):
    
    # Movement
    direction = 0
    
    # Animation
    frames = []
    current_frame = 0
    
    # Stats
    
    
    def __init__(self, x, y):
        
        pygame.sprite.Sprite.__init__(self)
        
        sprite_sheet = Spritesheet("sprites/jsquirt.png")
        frames = sprite_sheet.get_frames(JSQUIRT_SPRITE_X_SIZE, JSQUIRT_SPRITE_Y_SIZE)
        self.image = frames[0]
        self.rect = self.image.get_rect()
        
        self.rect.centerx = x
        self.rect.centery = y
    
class Explosion(pygame.sprite.Sprite):

    # Movement
    direction = 0
    
    # Animation
    frames = []
    current_frame = 0
    
    # Stats
    
    def __init__(self, x, y):
        
        pygame.sprite.Sprite.__init__(self)
        
        sprite_sheet = Spritesheet("sprites/explosion.png")
        frames = sprite_sheet.get_frames(EXPLOSION_SPRITE_X_SIZE, EXPLOSION_SPRITE_Y_SIZE)
        self.image = frames[0]
        self.rect = self.image.get_rect()
        
        self.rect.centerx = x
        self.rect.centery = y