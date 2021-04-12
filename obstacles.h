#ifndef OBSTACLES_H_INCLUDED
#define OBSTACLES_H_INCLUDED
#include "SDL.h"

typedef struct Obstacles
{
    SDL_Rect position;
    SDL_Surface* surface;
    SDL_Texture* texture;
    int spawnCounter;
} Obstacle;

Obstacle createObstacle(char directory[], SDL_Renderer* rend, int i);

void moveObstacle (Obstacle yourObstacles[]);

#endif // OBSTACLES_H_INCLUDED
