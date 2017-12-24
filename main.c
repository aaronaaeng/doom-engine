#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>

#define W 800
#define H 600

#define CamHeight 6
#define DuckHeight 2.5
#define HeadMargin 1
#define KneeHeight 2
#define hfov (0.73f*H)
#define vfov (0.2f*H)



static struct sector {
    float floor, ceiling;
    struct xy {
        float x, y;
    } *vertex;

    signed char *neighbors;
    unsigned npoints;
} *sectors = NULL;
static unsigned NumSectors = 0;

static struct player {
    struct xyz {
        float x, y, z;
    } where, velocity;

    float angle, anglesin, anglecos, yaw;
    unsigned sector;
} player;

