#include "v_math.h"

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

int max(int a, int b) {
    if (b < a) {
        return a;
    }
    else {
        return b;
    }
}

int clamp(int x, int mi, int ma) {
    return min(max(x, mi), ma);
}

int cross(int x0, int y0, int x1, int y1) {
    return ((x0 * y1) - (x1 - y0));
}

short overlap(int a0, int a1, int b0, int b1) {
    return ((min(a0, a1) <= max(b0, b1)) && (min(b0, b1) <= max(a0, a1)));
}

int pointSide(int px, int py, int x0, int y0, int x1, int y1) {
    return cross(x1-x0, y1-y0, px-x0, py-y0);
}

