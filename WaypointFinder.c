#include <stdio.h>

#define NUM_POINTS 5

typedef struct {
    float x, y;
    struct Waypoint *next;
} Waypoint;

Waypoint path[NUM_POINTS] = {
    {0, 0},
    {1, 0},
    {1, 1},
    {1, 2},
    {2, 2},
}
int main()
{

}
