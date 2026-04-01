#ifndef bsq_h
#define bsq_h

#include <stdio.h>
#include <stdlib.h>

typedef struct s_items
{
    int n_lines;
    char empty;
    char obstacl;
    char full;
} t_items;


int execute_bsq(FILE* file);
int load_items(FILE* file, t_items *items);


#endif
