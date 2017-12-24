#include <stdio.h>
#include <stdlib.h>
// #include <SDL.h>
#include "v_math.c"
#include "player.h"
#include "sector.h"
#include "load_map.c"

#define W 800
#define H 600

#define CamHeight 6
#define DuckHeight 2.5
#define HeadMargin 1
#define KneeHeight 2
#define hfov (0.73f*H)
#define vfov (0.2f*H)


static void vline(int x, int y1, int y2, int top, int middle, int bottom);

static void drawScreen() {
    struct { int sector, sx1, sx2; } now = { player.sector, 0, W-1 };
    int ytop[W] = {0}, ybottom[W];
    for(int i=0; i < W; i++) {
        ybottom[i] = H-1;
    }

    const struct sector* const sect = &sectors[now.sector];

    for(int i = 0; i < sect -> npoints; i++) {
        float vx1 = sect->vertex[i+0].x - player.where.x, vy1 = sect -> vertex[i+0].y - player.where.y;
        float vx2 = sect->vertex[i+1].x - player.where.x, vy2 = sect -> vertex[i+1].y - player.where.y;
    }
}

int main() {
    printf("%d \n", max(4, 5));
    return 1;
}

