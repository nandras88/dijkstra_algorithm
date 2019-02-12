//
// Created by Andras Noszka on 2019-02-12.
//

#include "dijkstra.h"

void put_into_list(int x, int y, list_t *list)
{
    list->list = (cord_t *)realloc(list->list, (list->list_size + 1) * sizeof(cord_t));
    list->list[list->list_size].x = x;
    list->list[list->list_size].y = y;
    list->list[list->list_size].visited = false;
    list->list_size++;
}

void set_cost(float cost[size][size], cord_t position, float inputMatrix[size][size], cord_t neighbour)
{
    float value = cost[position.x][position.y] + inputMatrix[neighbour.x][neighbour.y];
    cost[neighbour.x][neighbour.y] = value;
}

void set_pred(cord_t pred[size][size], cord_t position, cord_t neighbour)
{
    pred[neighbour.x][neighbour.y].x = position.x;
    pred[neighbour.x][neighbour.y].y = position.y;
}

cord_t min_cost(float cost[size][size], list_t *openList)
{

    float cost_min = __FLT_MAX__;
    int index_min = 0;

    for (int i = 0; i < openList->list_size; i++)
    {
        cord_t it = openList->list[i];
        float cost_it = cost[it.x][it.y];
        if (!it.visited && cost_it < cost_min)
        {
            cost_min = cost_it;
            index_min = i;
        }
    }

    openList->list[index_min].visited = true;

    return openList->list[index_min];
}

list_t get_neighbours(cord_t inputCord)
{
    list_t result = create_list();

    if (inputCord.x > 0)
    {
        put_into_list(inputCord.x - 1, inputCord.y, &result);
    }

    if (inputCord.x < size - 1)
    {
        put_into_list(inputCord.x + 1, inputCord.y, &result);
    }

    if (inputCord.y > 0)
    {
        put_into_list(inputCord.x, inputCord.y - 1, &result);
    }

    if (inputCord.y < size - 1)
    {
        put_into_list(inputCord.x, inputCord.y + 1, &result);
    }

    return result;
}

bool member_of_openlist(list_t *list, int x, int y)
{
    for (int i = 0; i < list->list_size; ++i)
    {
        if (list->list[i].x == x && list->list[i].y == y)
        {
            return true;
        }
    }

    return false;
}

bool is_goal(cord_t position)
{

    return (position.x == size - 1 && position.y == size - 1);
}

list_t create_list(void)
{

    list_t list;
    list.list = (cord_t *)malloc(sizeof(cord_t));
    list.list_size = 0;

    return list;
}
