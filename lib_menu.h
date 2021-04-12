#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"

#define MOUSE_OVER 1
#define MOUSE_CLICK 2

#define WINDOW_WIDTH (1920)
#define WINDOW_HEIGHT (1080)

#define START_MENU 0
#define GAME_ROOM 1
#define PAUSE_MENU 2


//en knapp som går att klicka på
typedef struct ClickableButtons
{
    SDL_Rect rect;
    int state;
    SDL_Surface* surface;
    SDL_Texture* texture;
} ClickableButton;

typedef struct Backgrounds
{
    SDL_Rect rect;
    SDL_Surface* surface;
    SDL_Texture* texture;
} Background;

//kollar om muspekaren är ovanför knappen och om användaren klickar och släpper med musknappen, returnerar då 1
int check_click(ClickableButton *yourButton,int mouse_x, int mouse_y);

//skapar/initierar en knapp
ClickableButton createButton(char directory[], SDL_Renderer* render);

//skapar en bakgrund som kan renderas
Background createBackground(char directory[], SDL_Renderer* render);
#endif
