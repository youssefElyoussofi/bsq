#ifndef bsq_h
#define bsq_h

#include <stdio.h>
#include <stdlib.h>

typedef struct s_elements
{
    int n_lines;
    char empty;
    char obstacl;
    char full;
} t_elements;


int execute_bsq(FILE* file);


#endif
