#include "header.h"

int main(int ac , char* av[])
{
    data *db;
    char* line = NULL;
    
    size_t len = 5;
    ssize_t read = 0;
    if (ac != 2)
    {
        fprintf(stderr,"enter one argement\n");
        return 1;
    }
    int fd = open(av[1],O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr,"error open file\n");
        return 1;
    }
    int status = parse_map(&db,fd);
    if (status == 0)
        return 1;
    return 0;
}