#include "bsq.h"

int execute_bsq(FILE* file)
{
    t_items items;
    if (load_items(file,&items) == -1)
        return -1;
    return 0;
}