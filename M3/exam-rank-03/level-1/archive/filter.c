#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 10000

void	search_buffer(char *buffer, int buf_len, char *search_str, int search_len)
{
	int		search_index;
	char	*search_found;

	search_index = 0;
	search_found = NULL;
	while (buffer[search_index] != 0)
	{
		if ((search_found = memmem(&buffer[search_index], buf_len, search_str, search_len)))
		{
			memset(search_found, '*', search_len);
			search_index += search_len;
			search_found = NULL;
		}
		else
			search_index++;
	}
	printf("%s", buffer);
}

int	main(int ac, char **av)
{
	char	read_char;
	char	*buffer;
	ssize_t	read_bytes;
	int		buf_index;
	int		search_len;

	if (ac != 2)
		return (1);
	if (av[1][0] == '\0')
		return (1);
	search_len = (int)strlen(av[1]);
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
	{
		perror("Error");
		return (1);
	}
	buf_index = 0;
	while ((read_bytes = read(0, &read_char, 1) != 0))
	{
		if (read_bytes < 0)
		{
			perror("Error");
			free(buffer);
			return (1);
		}
		buffer[buf_index++] = read_char;
		if (read_char == '\n')
		{
			buffer[buf_index] = '\0';
			search_buffer(buffer, strlen(buffer), av[1], search_len);
			buf_index = 0;
		}
	}
	buffer[buf_index] = '\0';
	search_buffer(buffer, strlen(buffer), av[1], search_len);
	free(buffer);
	return (0);
}
