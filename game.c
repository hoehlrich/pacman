#include "graphics.h"
#include "pacman.h"
#include "utils.h"

void updatedino(State *state) {
  if (state->dino->jumpstarted == -1) {
    return;
  }

  int dinoframe = state->frame - state->dino->jumpstarted;
  if (dinoframe < 6) {
    state->dino->y++;
  } else if (dinoframe > 10 && dinoframe < 17) {
    state->dino->y--;
  } else if (dinoframe > 16) {
    state->dino->jumpstarted = -1;
  }
}
