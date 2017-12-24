#ifndef PLAYER
#define PLAYER

static struct player {
    struct xyz {
        float x, y, z;
    } where, velocity;

    float angle, anglesin, anglecos, yaw;
    unsigned sector;
} player;

#endif