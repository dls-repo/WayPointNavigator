#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <stddef.h>


typedef struct {
    float x, y;
} Waypoint;

typedef struct {
    Waypoint current;
    Waypoint next;
    Waypoint next2;
} VisibleWindow;

#endif //WAYPOINT_H
