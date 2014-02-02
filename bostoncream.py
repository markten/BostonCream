import pygame
import game
import mainmenu

if __name__ == "__main__":
    main()

def main():
    
    ### Initialize status variables
    done = False
    inMenu = True
    
    ### Initialize pygame
    pygame.init()
    screen = pygame.display.set_mode(WINDOW_SIZE)
    pygame.display.set_caption("Boston Cream")
    screen.fill(BLACK)
    font = pygame.font.Font("/fonts/nokiafc22.ttf", 12)
    
    ### Create game clock
    clock = pygame.time.Clock()
    
    ### Create menu and game objects
    menu = MainMenu()
    game = Game()
    
    while not done:
        
        if inMenu:
            done = menu.handle_events()
            menu.handle_logic()
            menu.handle_graphics()
        
        if not inMenu:
            done = game.handle_events()
            game.handle_logic()
            game.handle_graphics()
            
        else:
            print("Error: Neither in menu or in game...")
    
    pygame.quit()