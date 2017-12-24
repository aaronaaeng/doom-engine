#ifndef SECTOR
#define SECTOR

static struct sector {
    float floor, ceiling;
    struct xy {
        float x, y;
    } *vertex;

    signed char *neighbors;
    unsigned npoints;
} *sectors = NULL;
static unsigned NumSectors = 0;

#endif