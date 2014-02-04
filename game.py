import pygame
from player import *
from enemies import *

class Game():
    
    ### Create object groups
    creme_trail = pygame.sprite.Group()
    jelly_squirts = pygame.sprite.Group()
    enemies = pygame.sprite.Group()
    all_sprites = pygame.sprite.Group()
    
    ### Define screen and player

    screen = []
    player = None
    
    def __init__(self, screen):

        self.screen = screen
        self.player = Player(START_X, START_Y)
        dhole = DonutHole(100, 100)
        jdonut = JellyDonut(200, 100)
        jsquirt = JellySquirt(300, 100)
        xplosion = Explosion(400, 100)
        pdonut = PlainDonut(600, 100)
        self.all_sprites.add(self.player, dhole, jdonut, jsquirt, xplosion, pdonut)
    
    def handle_events(self):
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return (True, None)
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    return (False, True)
                if event.key == pygame.K_UP:
                    self.player.moving = 1
                if event.key == pygame.K_DOWN:
                    self.player.moving = -1
                if event.key == pygame.K_LEFT:
                    self.player.turn_left()
                if event.key == pygame.K_RIGHT:
                    self.player.turn_right()
                if event.key == pygame.K_SPACE:
                    drop_cream_trail()
                    
            if event.type == pygame.KEYUP:
                if event.key == pygame.K_UP:
                    self.player.moving = 0
                if event.key == pygame.K_DOWN:
                    self.player.moving = 0
                """if event.key == pygame.K_LEFT:
                    print("L_UP")
                if event.key == pygame.K_RIGHT:
                    print("R_UP")"""
                    
        return (False, False)
        
    def handle_logic(self):
        self.all_sprites.update()
        pass
        
    def handle_graphics(self):
        self.screen.fill(BLACK)
        self.all_sprites.draw(self.screen)
        pygame.display.flip()