#include <stdbool.h>

#define DINOHEIGHT  4

typedef unsigned int Frame;

typedef struct {
    int x;
    int y;
    Frame jumpstarted;
} Dino;

typedef struct {
    unsigned int *pixels;
    Dino *dino;
    Frame frame;
    int fps;
} State;

void updatedino(State *state);

