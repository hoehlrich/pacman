#include "graphics.h"
#include "utils.h"

SDL_Context *SDL_InitContext() {
    ASSERT(SDL_Init(SDL_INIT_VIDEO) == 0,
            "Could not initialize SDL: %s\n", SDL_GetError());

    SDL_Context *ctx = malloc(sizeof(SDL_Context));
    ASSERT(ctx, "Could not create context: %s\n", SDL_GetError());

    SDL_Window *window = SDL_CreateWindow("pacman", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED, WINWIDTH,
                                          WINHEIGHT, SDL_WINDOW_SHOWN);
    ASSERT(window, "Could not create window: %s\n", SDL_GetError());

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    ASSERT(renderer, "Could not create renderer: %s\n", SDL_GetError());

    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                                             SDL_TEXTUREACCESS_STREAMING,
                                             SCREENWIDTH, SCREENHEIGHT);
    ASSERT(texture, "Could not create texture: %s\n", SDL_GetError());

    Uint32 lastupdate = SDL_GetTicks();

    ctx->window = window;
    ctx->renderer = renderer;
    ctx->texture = texture;
    ctx->lastupdate = lastupdate;

    return ctx;
}

void clearscreen(unsigned int *pixels, unsigned int color) {
    memset(pixels, color, SCREENWIDTH * SCREENHEIGHT * sizeof(unsigned int));
}

void drawgrid(unsigned int *pixels) {
    for (int i = 0; i < SCREENWIDTH*SCREENHEIGHT; i++) {
        int y = i / SCREENWIDTH;
        *(pixels + i) = (i + y % 2) % 2 ? WHITE : BLACK;
    }
}

void drawdino(unsigned int *pixels, int x, int y) {
    y = 9 - y;
    int xcoords[] = {x, x, x + 1, x + 1, x + 1, x + 2, x + 2};
    int ycoords[] = {y, y - 1, y - 1, y - 2, y - 3, y, y - 3};
    for (int i = 0; i < 7; i ++) {
        *(pixels + xcoords[i] + ycoords[i] * SCREENWIDTH) = WHITE;
    }
}

