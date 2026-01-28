/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:12:54 by timtan            #+#    #+#             */
/*   Updated: 2026/01/28 12:25:58 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_acknowledged;

void	acknowledge(int signal)
{
	if (signal == SIGUSR2)
		g_acknowledged = 1;
}

void	kill_check(void)
{
	if (errno == ESRCH)
		write(2, "Error, PID does not exist.\n", 27);
	else if (errno == EPERM)
		write(2, "Error, no permission to send signal\n", 36);
	else
		write(2, "Error.", 6);
	exit(1);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2))
				kill_check();
		}
		else
		{
			if (kill(pid, SIGUSR1))
				kill_check();
		}
		while (!g_acknowledged)
			usleep(1);
		g_acknowledged = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sigaction_s;
	int					pid;
	int					i;

	if (argc < 3 || argc > 3)
	{
		write(2, "Usage: ./client <pid> <string to send>\n", 39);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	ft_memset(&sigaction_s, 0, sizeof(sigaction_s));
	sigemptyset(&sigaction_s.sa_mask);
	sigaction_s.sa_flags = 0;
	sigaction_s.sa_handler = acknowledge;
	sigaction(SIGUSR2, &sigaction_s, NULL);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	return (0);
}
