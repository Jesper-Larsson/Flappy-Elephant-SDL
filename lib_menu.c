#include "lib_menu.h"
#include <stdio.h>
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"


int check_click(ClickableButton *yourButton,int mouse_x,int mouse_y)
{

    if (mouse_x - yourButton->rect.x >= 0 && mouse_x - yourButton->rect.x <= yourButton->rect.w && mouse_y - yourButton->rect.y >= 0 && mouse_y - yourButton->rect.y <= yourButton->rect.h)
    {
        switch(yourButton->state)
        {
            case 0:
            {
                if (!(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)))
                {
                    yourButton->state = 1;
                }
                return MOUSE_OVER;
            }

            case 1:
            {
                if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
                {
                    yourButton->state = 2;
                }
                return MOUSE_OVER;
            }

            default:
            {
                if (!(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)))
                {
                    yourButton->state = 0;
                    return MOUSE_CLICK;

                }
                else
                {
                    return MOUSE_OVER;
                }
            }
        }


    }

    else
    {
        yourButton->state = 0;
        return 0;
    }

}

ClickableButton createButton(char directory[], SDL_Renderer* render)
{
    ClickableButton yourButton;
    yourButton.surface = IMG_Load(directory);
    yourButton.texture = SDL_CreateTextureFromSurface(render, yourButton.surface);
    SDL_QueryTexture(yourButton.texture, NULL, NULL, &yourButton.rect.w, &yourButton.rect.h);
    yourButton.state = 0;
    return yourButton;
}


Background createBackground(char directory[], SDL_Renderer* render)
{
    Background yourBackground;
    yourBackground.surface = IMG_Load(directory);
    yourBackground.texture = SDL_CreateTextureFromSurface(render, yourBackground.surface);
    yourBackground.rect.w = WINDOW_WIDTH;
    yourBackground.rect.h = WINDOW_HEIGHT;
    yourBackground.rect.x = 0;
    yourBackground.rect.y = 0;
    return yourBackground;
}
