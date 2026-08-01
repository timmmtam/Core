#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	char	current_char;
	char	last_char;

	if (ac != 2)
		return (1);
	if (!av[1][0])
		return (1);
	sort_alphabetically();
	while (current_char != last_char)
	{
		show_permutations();
		current_to_last();
	}
}
