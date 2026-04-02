#include "bsq.h"

int execute_bsq(FILE* file)
{
    t_items items;
    if (load_items(file,&items) == -1)
        return -1;

    t_map map;
    if (load_map(file,&items,&map) == -1)
        return -1;
    return 0;
}