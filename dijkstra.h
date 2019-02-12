//
// Created by Andras Noszka on 2019-02-12.
//

#ifndef DIJKSTRA_ALGORITHM_DIJKSTRA_H
#define DIJKSTRA_ALGORITHM_DIJKSTRA_H

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdbool.h"

#define size 3

typedef struct
{
    int x;
    int y;
    bool visited;
    /* data */
} cord_t;

typedef struct
{
    cord_t *list;
    int list_size;
    /* data */
} list_t;

void put_into_list(int x, int y, list_t *list);
void set_cost(float cost[size][size], cord_t position, float inputMatrix[size][size], cord_t neighbour);
void set_pred(cord_t pred[size][size], cord_t position, cord_t neighbour);
cord_t min_cost(float cost[size][size], list_t *openList);
list_t get_neighbours(cord_t inputCord);
bool member_of_openlist(list_t *list, int x, int y);
bool is_goal(cord_t position);
list_t create_list(void);

#endif //DIJKSTRA_ALGORITHM_DIJKSTRA_H
