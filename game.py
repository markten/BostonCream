import pygame
from player import *
from enemies import *

class Game():
    
    ### Create object groups
    creme_trail = pygame.sprite.Group()
    jelly_squirts = pygame.sprite.Group()
    enemies = pygame.sprite.Group()
    all_sprites = pygame.sprite.Group()
    
    ### Create player and map
    player = Player()
    
    def handle_events(self):
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                if event.key == pygame.K_RIGHT:
                if event.key == pygame.K_RETURN:
                if event.key == pygame.K_SPACE:
            if event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT:
                if event.key == pygame.K_RIGHT:
