import pygame
from constants import *
from game import Game
from mainmenu import MainMenu
from player import *

def main():
    
    ### Initialize status variables
    done = False
    inMenu = True
    
    ### Initialize pygame
    pygame.init()
    screen = pygame.display.set_mode(WINDOW_SIZE)
    pygame.display.set_caption("Boston Cream")
    screen.fill(BLACK)
    
    ### Create game clock
    clock = pygame.time.Clock()
    
    ### Create menu and game objects
    print("Building menu")
    menu = MainMenu(screen)
    print("Building game")
    game = Game(screen)
    
    
    
    while not done:
        
        if inMenu:
            done, inMenu = menu.handle_events()
            menu.handle_logic()
            menu.handle_graphics()
        
        elif not inMenu:
            done, inMenu = game.handle_events()
            game.handle_logic()
            game.handle_graphics()
            
        else:
            print("Error: Neither in menu or in game...")
            
        clock.tick(FPS)
    
    pygame.quit()
    
if __name__ == "__main__":
    main()