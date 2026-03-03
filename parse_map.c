#include "header.h"

int parse_map(data **db, int fd)
{
    char *line = NULL;
    int count = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        count++;
        free(line);
    }
    return count;
}