#include "end.h"
#include "game.h"

void endGame(Game *yourGame)
{
    SDL_DestroyRenderer(yourGame->rend);
    SDL_DestroyWindow(yourGame->win);
    SDL_Quit();
}
