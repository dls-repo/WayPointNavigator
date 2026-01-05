#include <stdio.h>
#include <stdlib.h>

#define NUM_POINTS 5

typedef struct {
    float x, y;
} Waypoint;

typedef struct {
    Waypoint point;
    struct Node *next;
} Node;

Waypoint path[NUM_POINTS] = {
    {0, 0},
    {1, 0},
    {1, 1},
    {1, 2},
    {2, 2},
};

int main()
{
    Node *head = NULL;
    head = malloc(sizeof(Node));
    head->point = path[0];
    head->next = NULL;
//Test to confirm head points to the right place
    printf("x: %.1f, y: %.1f\n", head->point.x, head->point.y);
}
