#include "game.h"
#include "init.h"
#include "end.h"
#include "render.h"
#include <time.h>
#include <stdlib.h>

void runGame()
{
    //int randomNumber = rand();
    Game game2d = initGame();
    SDL_Event gameEvent;
    int jumping = 0;
    int spacePress = 0;
    int gameStarted = 0;
    while(1)
    {
        //printf("sen ar vardet %d \n", jumping);
        //if(!gameEvent)
        //{
            while(SDL_PollEvent(&gameEvent))
            {
                if (gameEvent.type == SDL_KEYDOWN && gameEvent.key.repeat == 0)
                    if(gameEvent.key.keysym.sym == SDLK_SPACE)
                    {
                        spacePress = 1;
                        printf("spacepress ar 1\n");
                    }
                    else
                    {
                        printf("spacepress ar 0\n");
                    }
                printf("ett varv \n");
            }
        //}


        SDL_GetMouseState(&game2d.mouseX, &game2d.mouseY);
        if(check_click(&game2d.quitButton, game2d.mouseX, game2d.mouseY)==MOUSE_CLICK)
        {
            endGame(&game2d);
            return;
        }


        //if(gameEvent.key.keysym.scancode == SDL_SCANCODE_SPACE)
        if(spacePress)
        {
            gameStarted = 1;
            game2d.player1.velocity = -20;
            spacePress = 0;
        }
        movePlayer(&game2d.player1);
        if(gameStarted){
            moveObstacle(game2d.boxes);
            for(int i = 0; i<2; i++){
                if(SDL_HasIntersection(&game2d.player1.body, &game2d.boxes[i].position))
                {
                    resetGame(&game2d);
                    gameStarted = 0;
                }
            }
            if(game2d.player1.body.y < 0 || game2d.player1.body.y > 1080-game2d.player1.body.h)
                {
                    resetGame(&game2d);
                    gameStarted = 0;
                }
        }
        else{
            game2d.player1.velocity = 0;
        }
        //SDL_Delay(1000/60);
        renderGame(&game2d);
    }
}

