#include <SDL.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int RECT_WIDTH = 50;
const int RECT_HEIGHT = 50;
const int MOVE_SPEED = 2;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;


int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Rectangle Move Animation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
