#include <stdio.h>
#include "pacman.h"
#include "graphics.h"

State *init_state();
void quit(State *state, SDL_Context *ctx);

int main() {
    SDL_Context *ctx = SDL_InitContext();
    State *state = init_state();

    while (++(state->frame)) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit(state, ctx);
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_w:
                            if (state->dino->jumpstarted == -1) {
                                state->dino->jumpstarted = state->frame;
                            }
                            break;
                    }
                    break;
            }
        }
        
        clearscreen(state->pixels, BLACK);

        // drawgrid(state->pixels);
        drawdino(state->pixels, state->dino->x, state->dino->y);
        updatedino(state);

        SDL_UpdateTexture(ctx->texture, NULL, state->pixels, SCREENWIDTH * sizeof(unsigned int));
        SDL_RenderClear(ctx->renderer);
        SDL_RenderCopy(ctx->renderer, ctx->texture, NULL, NULL);
        SDL_RenderPresent(ctx->renderer);

        ctx->lastupdate = SDL_GetTicks();
        while ((SDL_GetTicks() - ctx->lastupdate) < (1000 / state->fps)) {};
    }
}

State *init_state() {
    State *state = malloc(sizeof(State));
    state->pixels = malloc(sizeof(unsigned int) * SCREENWIDTH * SCREENHEIGHT);
    state->dino = malloc(sizeof(Dino));
    state->dino->x = 2;
    state->dino->y = 0;
    state->dino->jumpstarted = -1;
    state->frame = 0;
    state->fps = 20;
    return state;
}

void quit(State *state, SDL_Context *ctx) {
    free(state->pixels);
    free(state->dino);
    SDL_DestroyTexture(ctx->texture);
    SDL_DestroyRenderer(ctx->renderer);
    SDL_DestroyWindow(ctx->window);
    SDL_Quit();
    exit(0);
}

