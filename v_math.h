// And other math operations I realized also should be included

#include <math.h>
#include "xy.h"

#ifndef V_MATH
#define V_MATH

int min(int a, int b);
int max(int a, int b);

int clamp(int x, int min, int max);

int cross(int x0, int y0, int x1, int y1);

short overlap(int x0, int y0, int x1, int y1);

short intersect(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);

int pointSide(int px, int py, int x0, int y0, int x1, int y1);

struct xy intersectPoint(int x0, int y0, int x1, int y1, 
                    int x2, int y2, int x3, int y3);

#endif