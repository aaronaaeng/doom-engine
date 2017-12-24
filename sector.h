#include "xy.h"

#ifndef SECTOR
#define SECTOR

static struct sector {
    float floor, ceiling;
    struct xy *vertex;
    signed char *neighbors;
    unsigned npoints;
};

#endif