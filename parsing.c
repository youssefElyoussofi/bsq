#include "bsq.h"

int load_items(FILE* file, t_items *items)
{
    int read = fscanf(file,"%d%c%c%c",&items->n_lines,&items->empty,&items->obstacl,&items->full);
    if (read != 4)
        return -1;
    //......
    return 1;
}