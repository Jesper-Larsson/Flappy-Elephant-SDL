#include "player.h"
#include <stdio.h>
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"



Player createPlayer(char directory[], char trunkDirectory[], SDL_Renderer* renderer)
{
    Player yourPlayer;
    yourPlayer.surface = IMG_Load(directory);
    yourPlayer.texture = SDL_CreateTextureFromSurface(renderer, yourPlayer.surface);
    yourPlayer.body.h = 200;
    yourPlayer.body.w = 200;

    yourPlayer.body.x = 500;
    yourPlayer.body.y = 500;
    yourPlayer.surface = IMG_Load(trunkDirectory);
    yourPlayer.trunkTexture = SDL_CreateTextureFromSurface(renderer, yourPlayer.surface);
    yourPlayer.trunkRects[0].w = 20;
    yourPlayer.trunkRects[0].h = 60;
    for(int i=1; i<TRUNK_LENGHT;i++)
    {
        //yourPlayer.trunkRects[i].w = yourPlayer.trunkRects[i-1].w - 3;
        yourPlayer.trunkRects[i].w = yourPlayer.trunkRects[i-1].w;
        yourPlayer.trunkRects[i].h = yourPlayer.trunkRects[i-1].h-1;
    }
    yourPlayer.trunkRects[0].x = yourPlayer.body.x+yourPlayer.body.w-yourPlayer.trunkRects[0].w/2;
    yourPlayer.trunkRects[0].y = yourPlayer.body.y+70;
    for(int i=1; i<TRUNK_LENGHT; i++)
    {
        yourPlayer.trunkRects[i].x = yourPlayer.trunkRects[i-1].x+yourPlayer.trunkRects[i-1].w/5;
        yourPlayer.trunkRects[i].y = yourPlayer.trunkRects[i-1].y;
    }

    yourPlayer.jumpState = 0;
    yourPlayer.velocity = 5;
    return yourPlayer;
}

void movePlayer(Player *yourPlayer)
{
    yourPlayer->body.y+=yourPlayer->velocity;
    yourPlayer->trunkRects[0].y = yourPlayer->body.y+70;
    for(int i=TRUNK_LENGHT-1; i>1; i--)
    {
        yourPlayer->trunkRects[i].y = (yourPlayer->trunkRects[i].y + yourPlayer->trunkRects[i-1].y) /2;
    }

    //if(yourPlayer->trunkRects[0].y > yourPlayer->body.y+40)
      //  {
        //    yourPlayer->trunkRects[0].y = yourPlayer->body.y+40;
        //}
        //else if(yourPlayer->trunkRects[0].y < yourPlayer->body.y-40)
        //{
        //    yourPlayer->trunkRects[0].y = yourPlayer->body.y-40;
        //}

    for(int i = 1; i<TRUNK_LENGHT; i++)
    {
        if(yourPlayer->trunkRects[i].y > yourPlayer->trunkRects[i-1].y+i/2)
        {
            yourPlayer->trunkRects[i].y = yourPlayer->trunkRects[i-1].y+i/2;
        }
        else if(yourPlayer->trunkRects[i].y < yourPlayer->trunkRects[i-1].y-i/2)
        {
            yourPlayer->trunkRects[i].y = yourPlayer->trunkRects[i-1].y-i/2;
        }
    }

    yourPlayer->velocity++;

}

