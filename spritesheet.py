import pygame
from constants import *

class Spritesheet():
    
    sprite_sheet = None
    
    def __init__(self, file_name):
        self.sprite_sheet = pygame.image.load(file_name).convert()
        
    def get_image(self, x, y, width, height):
        image = pygame.Surface([width, height]).convert()
        image.blit(self.sprite_sheet, (0, 0), (x, y, width, height))
        image.set_colorkey(GREEN)
        
        return image
       

    def get_frames(self, sprite_width, sprite_height):
        
        frames = []
        
        for yindex in range(self.sprite_sheet.get_rect().h / sprite_height):
            for xindex in range(self.sprite_sheet.get_rect().w / sprite_width):
                image = self.get_image( xindex * sprite_width, yindex * sprite_height, sprite_width, sprite_height)
                frames.append(image)
                
        return frames
              