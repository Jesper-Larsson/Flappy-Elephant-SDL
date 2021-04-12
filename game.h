#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <stdio.h>
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_timer.h"
#include "SDL_image.h"
#include "lib_menu.h"
#include "player.h"
#include "obstacles.h"

#define WINDOW_WIDTH (1920)
#define WINDOW_HEIGHT (1080)
#define NUMBER_OF_BOXES 3
typedef struct Games
{
    SDL_Window* win;
    SDL_Renderer* rend;
    Player player1;
    Obstacle boxes[NUMBER_OF_BOXES];
    Background background1;
    ClickableButton quitButton;
    int mouseX;
    int mouseY;
    int closestTrunkRect;
    int trunkDirection;
    int trunkCounter;

} Game;

void runGame();

#endif // GAME_H_INCLUDED
