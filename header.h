#ifndef HEADER_H
#define HEADER_H

#define BUFFER_SIZE 10

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
    char **lines;
    size_t len;
    char empty;
    char full;
    char obstacle;
} data;

char* get_next_line(int fd);
int parse_map(data **db, int fd);

ssize_t	find_newline(char *s);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *buf, char *tmp);
char	*ft_substr(char *s, ssize_t st, ssize_t len);
char	*ft_strdup(char	*str);
char	*get_next_line(int fd);

#endif