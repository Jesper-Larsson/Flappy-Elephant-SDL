#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"

#define NEW_JUMP 30
#define TRUNK_LENGHT 30

typedef struct Players
{
    SDL_Rect body;
    SDL_Rect trunkRects[TRUNK_LENGHT];
    //SDL_rect shoes;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Texture* trunkTexture;
    int jumpState;
    int velocity;
} Player;

Player createPlayer(char directory[], char trunkDirectory[], SDL_Renderer* renderer);
void movePlayer(Player *yourPlayer);

#endif // CHARACTERS
