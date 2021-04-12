#include "init.h"
#include "game.h"
#include "player.h"
#include "lib_menu.h"

Game initGame()
{
    Game yourGame;

    //initiering av grafik
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) !=0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        //return 1;
    }

    yourGame.win = SDL_CreateWindow("Flappy Man Adventures",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!yourGame.win)
    {
        printf("error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        //return 1;
    }

    //skapa en renderare som ordnar hårdvaran
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    yourGame.rend = SDL_CreateRenderer(yourGame.win, -1, render_flags);
    if (!yourGame.rend)
    {
        printf("error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(yourGame.win);
        SDL_Quit();
        //return 1;
    }
    yourGame.background1 = createBackground("resources/b1.jpg", yourGame.rend);
    yourGame.player1 = createPlayer("resources/player.png", "resources/trunk.png", yourGame.rend);
    for(int i = 0; i < 2 ; i++){
        yourGame.boxes[i] = createObstacle("resources/box.png", yourGame.rend, i);
    }
    yourGame.quitButton = createButton("resources/player.png", yourGame.rend);
    yourGame.quitButton.rect.x = 0; yourGame.quitButton.rect.y = 0; yourGame.quitButton.rect.w = 1920; yourGame.quitButton.rect.h = 1080;
    yourGame.closestTrunkRect=0;
    yourGame.trunkDirection =0;
    yourGame.trunkCounter = 0;
    return yourGame;

}

void resetGame(Game* yourGame)
{
    yourGame->player1.body.y = 500;
    yourGame->boxes[0].position.x = 1900;
    yourGame->boxes[1].position.x = 3000;
}
