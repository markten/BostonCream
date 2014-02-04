import pygame
from constants import *

class MainMenu():
    
    screen = []
    text_visible = True
    menu_text = []
    
    def __init__(self, screen):
        
        self.screen = screen
        # Create a font
        self.title_font = pygame.font.Font("fonts/nokiafc22.ttf", 42)
        self.subtitle_font = pygame.font.Font("fonts/nokiafc22.ttf", 12)
        pygame.time.set_timer(BLINK_TIMER, 500)
        self.generate_text()
        
    def handle_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return (True, None)
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    return (False, False)
            if event.type == BLINK_TIMER:
                self.text_visible = not self.text_visible
                self.generate_text()
        return (False, True)
        
    def handle_logic(self):
        
        pass
        
    def handle_graphics(self):
        self.screen.fill(BLACK)
        self.display_text()
        pygame.display.flip()
    
    def display_text(self):
        
        for text in self.menu_text:
            self.screen.blit(text[0], text[1])
        
    def generate_text(self):
        
        # Clear text array
        self.menu_text = []
        
        # Title Text
        self.title_text = self.title_font.render("Boston Cream", True, WHITE)
        self.title_text_Rect = self.title_text.get_rect()
        self.title_text_Rect.centerx = self.screen.get_rect().centerx
        self.title_text_Rect.centery = WINDOW_Y_SIZE / 2
        self.menu_text.append((self.title_text, self.title_text_Rect))

        # Subtitle Text
        self.subtitle_text = self.subtitle_font.render("A delightful digital divertisement dealing with donuts!", True, WHITE)
        self.subtitle_text_Rect = self.subtitle_text.get_rect()
        self.subtitle_text_Rect.centerx = self.screen.get_rect().centerx
        self.subtitle_text_Rect.centery = self.title_text_Rect.centery + 30
        self.menu_text.append((self.subtitle_text, self.subtitle_text_Rect))
        
        # Press Enter Text
        if self.text_visible:
            self.press_enter_text = self.subtitle_font.render("Press Enter...", True, WHITE)
            self.press_enter_text_Rect = self.press_enter_text.get_rect()
            self.press_enter_text_Rect.centerx = self.screen.get_rect().centerx
            self.press_enter_text_Rect.centery = self.subtitle_text_Rect.centery + 40
            self.menu_text.append((self.press_enter_text, self.press_enter_text_Rect))
