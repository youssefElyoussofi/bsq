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

typedef struct s_map
{
    char **map;
    size_t height;
    size_t weight;
} t_map;

typedef struct s_square
{
    int size;
    int i;
    int j;
}t_square;

int execute_bsq(FILE* file);
int load_items(FILE* file, t_items *items);
int load_map(FILE* file, t_items *items, t_map *map);

char *ft_strdup(const char *str);
size_t ft_strlen(const char *str);
int clean(t_map *map, char *line, int status_ret);

#endif
