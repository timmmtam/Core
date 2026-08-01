/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:53:12 by timtan            #+#    #+#             */
/*   Updated: 2026/01/28 11:05:02 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_builder(int signal, siginfo_t *info, void *context)
{
	static int	bit_count;
	static char	c;

	(void)context;
	if (signal == SIGUSR2)
		c |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		bit_count = 0;
		write (1, &c, 1);
		c = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sigaction_s;

	ft_memset(&sigaction_s, 0, sizeof(sigaction_s));
	sigemptyset(&sigaction_s.sa_mask);
	ft_printf("PID: %d\n", getpid());
	sigaction_s.sa_flags = SA_SIGINFO;
	sigaction_s.sa_sigaction = char_builder;
	sigaction(SIGUSR1, &sigaction_s, NULL);
	sigaction(SIGUSR2, &sigaction_s, NULL);
	while (1)
		pause();
	return (0);
}
