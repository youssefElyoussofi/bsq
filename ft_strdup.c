#include "bsq.h"

size_t ft_strlen(const char *str)
{
    size_t len = 0;
    while (str && str[len])
    {
        len++;
    }
    return len;
}

char *ft_strdup(const char *str)
{
    size_t len = ft_strlen(str);
    char *ptr = NULL;
    ptr = malloc((len + 1) * sizeof(char));
    if (!ptr)
        return NULL;
    size_t i = 0;
    while (i < len)
    {
        ptr[i] = str[i];
        i++;
    }
    ptr[i] = 0;
    return ptr;
}