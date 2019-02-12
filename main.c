#include "dijkstra.h"

int main()
{

    list_t openList = create_list();
    cord_t position;
    cord_t pred[3][3];
    float cost[size][size];

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cost[i][j] = __FLT_MAX__;
        }
    }

    float test_matrix[size][size] = {
            {2, 5, 8},
            {3, 4, 7},
            {5, 2, 1}};

    //Starting position set
    position.x = 0;
    position.y = 0;
    cost[position.x][position.y] = test_matrix[position.x][position.y];

    do
    {
        list_t neighbours = get_neighbours(position);
        for (int i = 0; i < neighbours.list_size; i++)
        {
            cord_t ne = neighbours.list[i];
            if (true != member_of_openlist(&openList, ne.x, ne.y))
            {
                put_into_list(ne.x, ne.y, &openList);
                set_cost(cost, position, test_matrix, ne);
                set_pred(pred, position, ne);
            }
        }

        position = min_cost(cost, &openList);

    } while (is_goal(position) != true);

    printf("The total coast of the trip %.f\n", cost[size - 1][size - 1]);

    return 0;
}