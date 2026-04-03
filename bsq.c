#include "bsq.h"

void	ft_bzero(void *s, size_t n)
{
	char	*v;
	size_t	i;

	v = (char *)s;
	i = 0;
	while (i < n)
	{
		v[i] = 0;
		i++;
	}
}

int found_min(int top, int left, int topleft)
{
    int min = topleft;
    if (top < min)
        min = top;
    if (left < min)
        min = left;
    return min;
}

void found_big_square(t_square *square, t_items *items, t_map *map)
{
    square->size = 0;
    square->i = 0;
    square->j = 0;

    
    int matrix[map->height][map->weight];
    ft_bzero(&matrix,sizeof(matrix));
    for (int i = 0; i < map->height; ++i)
    {
        for (int j = 0; j < map->weight; ++j)
        {
            if (map->map[i][j] == items->obstacl)
                matrix[i][j] = 0;
            else if (i == 0 || j == 0)
                matrix[i][j] = 1;
            else
            {
                int min = found_min(matrix[i - 1][j],matrix[i][j - 1],matrix[i - 1][j - 1]);
                //.....
            }
        }
    }
    
}

int execute_bsq(FILE* file)
{
    t_items items;
    if (load_items(file,&items) == -1)
        return -1;

    t_map map;
    if (load_map(file,&items,&map) == -1)
        return -1;

    t_square square;
    found_big_square(&square,&items,&map);

    //....
    //....
    return 0;
}