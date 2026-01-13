#include <stdio.h>
#include <stdlib.h>

#define NUM_POINTS 7

typedef struct {
    float x, y;
} Waypoint;

typedef struct {
    Waypoint current;
    Waypoint next;
    Waypoint next2;
} VisibleWindow;

//TODO Create program that is feeding the x and y to the robot rather than pre-defined path
Waypoint path[NUM_POINTS] = {

    {0, 0},
    {1, 0},
    {1, 1},
    {1, 2},
    {2, 2},
    {2, 3},
    {3, 3},
    
};

int getNextWaypoint(Waypoint *locationData)
{
    //make index static so it remembers its place for the next function call
    static int index = 0;
    if ( index >= NUM_POINTS) return 0;

    // Writing the location data of the next point in the path to the address
    *locationData = path[index++];
    return 1;
}

void robot_step(VisibleWindow *knownLocationData)
{
    printf("Current: (%.1f, %.1f), Next: (%.1f, %.1f), Next2: (%.1f, %.1f)\n",
           knownLocationData->current.x, knownLocationData->current.y,
           knownLocationData->next.x, knownLocationData->next.y,
           knownLocationData->next2.x, knownLocationData->next2.y);
}


int main()
{
    VisibleWindow bot;

    if (!getNextWaypoint(&bot.current)) return 0;
    if (!getNextWaypoint(&bot.next)) return 0;
    if (!getNextWaypoint(&bot.next2)) return 0;

    while (1) {

        robot_step(&bot);
        bot.current	= bot.next;
        bot.next	= bot.next2;

        if (!getNextWaypoint(&bot.next2)) {

            robot_step(&bot);
            bot.current	= bot.next;
            bot.next	= bot.next2;

            robot_step(&bot);
            bot.current	= bot.next;
            bot.next	= bot.next2;
            break;

        }
    }

    return 0;
}
