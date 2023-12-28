#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int RECT_WIDTH = 50;
const int RECT_HEIGHT = 50;
const int MOVE_SPEED = 2;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

void renderRectangles(int x1, int x2) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
    SDL_RenderClear(renderer);

    // Draw the first rectangle
    SDL_Rect rect1 = {x1, SCREEN_HEIGHT / 2 - RECT_HEIGHT / 2, RECT_WIDTH, RECT_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &rect1);

    // Draw the second rectangle
    SDL_Rect rect2 = {x2, SCREEN_HEIGHT / 2 - RECT_HEIGHT / 2, RECT_WIDTH, RECT_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color
    SDL_RenderFillRect(renderer, &rect2);

    SDL_RenderPresent(renderer);
}

void moveRectangles(int *x1, int *x2, int target1, int target2) {
    if (*x1 != target1) {
        if (*x1 < target1) {
            *x1 += MOVE_SPEED;
        } else {
            *x1 -= MOVE_SPEED;
        }
    }

    if (*x2 != target2) {
        if (*x2 < target2) {
            *x2 += MOVE_SPEED;
        } else {
            *x2 -= MOVE_SPEED;
        }
    }
}
int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Rectangle Move Animation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int rect1_x = 50;
    int rect2_x = SCREEN_WIDTH - RECT_WIDTH - 50;
    int target1 = SCREEN_WIDTH - RECT_WIDTH - 50;
    int target2 = 50;

    SDL_Event e;
    int quit = 0;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        moveRectangles(&rect1_x, &rect2_x, target1, target2);
        renderRectangles(rect1_x, rect2_x);
        SDL_Delay(10); // Adjust the delay as needed
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
