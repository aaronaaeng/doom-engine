#include "v_math.h"
#include "sector.h"

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
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

short intersect(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    return overlap(x0, x1, x2, x3) && overlap(y0, y1, y2, y3);
}

int pointSide(int px, int py, int x0, int y0, int x1, int y1) {
    return cross(x1-x0, y1-y0, px-x0, py-y0);
}

struct xy intersectPoint(int x0, int y0, int x1, int y1, 
    int x2, int y2, int x3, int y3) {
        struct xy point = {
            cross(cross(x0, y0, x1, y1), x0-x1, cross(x2, y2, x3, y3), x2-x3) / cross(x0-x2, y0-y1, x2-x3, y2-y3), \
            cross(cross(x0, y0, x1, y1), y0-y1, cross(x2, y2, x3, y3), y2-y3) / cross(x0-x2, y0-y1, x2-x3, y2-y3)
        }; 
        return point;
    }
