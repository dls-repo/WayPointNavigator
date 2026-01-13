#include "waypoint.h"
#include <stdio.h>

Waypoint path[] = {

    {0, 0},
    {1, 0},
    {1, 1},
    {1, 2},
    {2, 2},
    {2, 3},
    {3, 3},
    
};

#define NUM_POINTS (sizeof(path)/sizeof(path[0]))

int get_next_waypoint(Waypoint *locationData)
{
    static size_t index = 0;
    if ( index >= NUM_POINTS) return 0;

    *locationData = path[index++];
    return 1;
}
