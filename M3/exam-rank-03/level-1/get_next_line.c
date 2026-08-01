#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

static int		has_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*extract_str(char *str)
{
	char	*extracted_str;
	int		str_len;
	int		i;

	str_len = 0;
	i = 0;
	while (str[str_len])
		str_len++;
	extracted_str = malloc(str_len + 1);
	if (!extracted_str)
		return (NULL);
	if (has_newline(str))
	{
		while (*str != '\n')
			extracted_str[i++] = *str++;
		extracted_str[i++] = '\n';
	}
	else
	{
		while (*str != '\0')
			extracted_str[i++] = *str++;
	}
	extracted_str[i] = '\0';
	return (extracted_str);
}

char	*get_next_line(int fd)
{
	static char	stash[1000000];
	static char	*stash_pos = stash;
	ssize_t		read_bytes;
	char		read_buf[BUFFER_SIZE + 1];
	char		*line;
	char		*stash_read;
	int			i;

	stash_read = stash_pos;
	while (!has_newline(stash_pos))
	{
		read_bytes = read(fd, read_buf, BUFFER_SIZE);
		if (read_bytes <= 0)
			break;
		read_buf[read_bytes] = '\0';
		i = 0;
		while (read_buf[i] != '\0')
			*stash_read++ = read_buf[i++];
		*stash_read = '\0';
	}
	line = extract_str(stash_pos);
	stash_pos = ++stash_read;
	if (!line || line[0] == '\0')
		return (free(line), NULL);
	else
		return(line);
}
