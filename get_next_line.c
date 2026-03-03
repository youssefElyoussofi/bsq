#include "header.h"

static char	*extract_line(char **str)
{
	char	*line;
	char	*new_buf;
	ssize_t	index;

	index = find_newline(*str);
	if (index >= 0)
	{
		line = ft_substr(*str, 0, index + 1);
		new_buf = ft_substr(*str, index + 1, ft_strlen(*str) - index - 1);
		if (!line || !new_buf)
		{
			free(line);
			free(new_buf);
			return (NULL);
		}
		free(*str);
		*str = new_buf;
	}
	else
	{
		line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
	}
	return (line);
}

static char	*free_all(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*tmp;
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (find_newline(buf) == -1)
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		tmp[read_bytes] = '\0';
		buf = ft_strjoin(buf, tmp);
		if (!buf)
			return (NULL);
	}
	free(tmp);
	if (!buf || *buf == '\0')
		return (free_all(&buf));
	return (extract_line(&buf));
}