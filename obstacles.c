#include "obstacles.h"
#include "game.h"
#include "SDL.h"
#include <stdlib.h>

Obstacle createObstacle(char directory[], SDL_Renderer* rend, int i)
{
    Obstacle yourObstacle;
    yourObstacle.surface = IMG_Load(directory);
    yourObstacle.texture = SDL_CreateTextureFromSurface(rend, yourObstacle.surface);
    SDL_QueryTexture(yourObstacle.texture, NULL, NULL, &yourObstacle.position.w, &yourObstacle.position.h);
    yourObstacle.position.h /=3;
    yourObstacle.position.x = 1900 + 1100*i; yourObstacle.position.y = rand()%500;
    return yourObstacle;
}

void moveObstacle(Obstacle yourObstacles[])
{
    for (int i = 0; i< 3; i++){
        yourObstacles[i].position.x -= 10;
        if (yourObstacles[i].position.x <(0 - yourObstacles[i].position.w))
        {
            yourObstacles[i].position.x = 1920;
            yourObstacles[i].position.y = rand()%(1080-yourObstacles[i].position.h);
        }
    }
}
