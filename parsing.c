#include "bsq.h"

int load_items(FILE* file, t_items *items)
{
    int read = fscanf(file,"%d%c%c%c",&items->n_lines,&items->empty,&items->obstacl,&items->full);
    if (read != 4)
        return -1;

    if (items->n_lines <= 0)
        return -1;
    if (items->empty == items->obstacl || items->empty == items->full || items->full == items->obstacl)
        return -1;
    if (items->empty < 32 || items->empty > 126)
        return -1;
    if (items->full < 32 || items->full > 126)
        return -1;
    if (items->obstacl < 32 || items->obstacl > 126)
        return -1;
    return 0;
}

int clean(t_map *map, char *line, int status_ret)
{
    if (map->map)
    {
        int i = 0;

        while (map->map[i] != NULL)
        {
            free(map->map[i]);
            i++;
        }
        free(map->map);
    }
    if (line)
        free (line);
    return status_ret;
}

int check_map_items(t_map *map, t_items *items)
{
    size_t i = 0;
    while (i < map->height)
    {
        size_t j = 0;
        while (j < map->weight)
        {
            if (map->map[i][j] != items->empty && map->map[i][j] != items->obstacl)
                return -1;
            j++;
        }
        i++;
    }
    return 0;
}

int load_map(FILE* file, t_items *items, t_map *map)
{
    char *line = NULL;
    map->height = items->n_lines;
    size_t len = 0;

    map->map = malloc((items->n_lines + 1) * sizeof(char *));
    if (!map->map)
        return -1;
    map->map[items->n_lines] = NULL;

    if (getline(&line,&len,file) == -1)
        return clean(map,line,-1);
    for (int i = 0; i < items->n_lines; i++)
    {
        int read = getline(&line,&len,file);
        if (read == -1)
            return clean(map,line,-1);
        if (line[read - 1] == '\n')
            line[--read] = 0;
        else
            return clean(map,line,-1);
        if (i == 0)
            map->weight = read;
        if (map->weight != read)
            return clean(map,line,-1);
        map->map[i] = ft_strdup(line);
        if (line)
        {
            free(line);
            line = NULL;
        }
    }
    if (check_map_items(map,items) == -1)
        return clean(map,NULL,-1);
    else
    {
        for (size_t i = 0; i < map->height; ++i)
        {
            printf("%s\n",map->map[i]);
        }
    }
    return 0;
}