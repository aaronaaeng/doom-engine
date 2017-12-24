#include <stdio.h>
#include <stdlib.h>
// #include <SDL.h>
#include "v_math.c"
#include "player.h"
#include "sector.h"

#define W 800
#define H 600

#define CamHeight 6
#define DuckHeight 2.5
#define HeadMargin 1
#define KneeHeight 2
#define hfov (0.73f*H)
#define vfov (0.2f*H)

struct player player;
struct sector *sectors = NULL;
static unsigned numSectors = 0;


int main() {
    printf("%d \n", max(4, 5));
    return 1;
}