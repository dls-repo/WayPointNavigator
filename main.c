#include "waypoint.h"
#include <stdio.h>

int get_next_waypoint(Waypoint *locationData);

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

    if (!get_next_waypoint(&bot.current)) return 0;
    if (!get_next_waypoint(&bot.next)) return 0;
    if (!get_next_waypoint(&bot.next2)) return 0;

    while (1) {

        robot_step(&bot);
        bot.current	= bot.next;
        bot.next	= bot.next2;

        if (!get_next_waypoint(&bot.next2)) {

	    //Finish remaining steps
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
