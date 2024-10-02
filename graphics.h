#include <SDL2/SDL.h>

#define SCREENWIDTH     28
#define SCREENHEIGHT    10
#define WINWIDTH    (SCREENWIDTH*60)
#define WINHEIGHT   (SCREENHEIGHT*60)

#define WHITE   0x00ffffff
#define BLACK   0x00000000

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Uint32 lastupdate;
    SDL_Rect *dstrect;
} SDL_Context;

SDL_Context *SDL_InitContext();

void clearscreen(unsigned int *pixels, unsigned int color);
void drawgrid(unsigned int *pixels);
void drawdino(unsigned int *pixels, int x, int y);

