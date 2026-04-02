#include "bsq.h"

int execute_file_argement(const char *filename)
{
    FILE* file;

    file = fopen(filename,"r");
    if (!file)
        return -1;
    if (execute_bsq(file) == -1)
        return -1;
    fclose(file);
}


int main(int ac , char* av[])
{
    if (ac == 1)
    {
        if (execute_bsq(stdin) == -1)
            fprintf(stderr,"map error\n");
    }
    else
    {
        int i = 1;
        while (i < ac)
        {
            if (execute_file_argement(av[i]) == -1)
                fprintf(stderr,"map error\n");
            i++;
        }
    }
    return 0;
}