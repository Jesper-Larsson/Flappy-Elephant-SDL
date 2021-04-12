#include "render.h"
#include "game.h"

void renderGame(Game *yourGame)
{
    SDL_RenderClear(yourGame->rend);

    SDL_RenderCopy(yourGame->rend, yourGame->background1.texture, NULL, &yourGame->background1.rect);

    SDL_RenderCopy(yourGame->rend, yourGame->player1.texture, NULL, &yourGame->player1.body);

    for(int i = 0; i< 3; i++){

        SDL_RenderCopy(yourGame->rend, yourGame->boxes[i].texture, NULL, &yourGame->boxes[i].position);
    }
/*
    yourGame->closestTrunkRect = 0;
    for (int i = 1; i<TRUNK_LENGHT; i++)
    {
        if (yourGame->player1.trunkRects[i].y > yourGame->player1.trunkRects[i-1].y)
        {
            yourGame->closestTrunkRect = i;
        }
    }
*/

  /*  if(yourGame->trunkCounter)
    {
        yourGame->trunkCounter--;
    }
    else
    {
        if(!yourGame->trunkDirection)
        {
            yourGame->closestTrunkRect++;
            if (yourGame->closestTrunkRect==30)
            {
                yourGame->trunkDirection = 1;

            }
        }
        else
        {
            yourGame->closestTrunkRect--;
            if (yourGame->closestTrunkRect==0)
            {
                yourGame->trunkDirection=0;
            }

        }
        yourGame->trunkCounter = 0;
    }*/

    for (int i = 0; i < yourGame->closestTrunkRect; i++)
    {
        SDL_RenderCopy(yourGame->rend, yourGame->player1.trunkTexture, NULL, &yourGame->player1.trunkRects[i]);
    }
    for (int i=TRUNK_LENGHT-1; i>=yourGame->closestTrunkRect; i--)
    {
        SDL_RenderCopy(yourGame->rend, yourGame->player1.trunkTexture, NULL, &yourGame->player1.trunkRects[i]);
    }


    SDL_RenderPresent(yourGame->rend);
}
