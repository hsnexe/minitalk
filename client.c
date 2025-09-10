/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashammo <hashammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:20:23 by hashammo          #+#    #+#             */
/*   Updated: 2025/09/10 15:21:42 by hashammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_client = 0;

void	safe_kill(__pid_t pid, int signal)
{
	if (kill (pid, signal) < 0)
	{
		write (2, "ERROR", 5);
		exit(EXIT_FAILURE);
	}
}

void	ack_handler(int signal)
{
	(void)signal;
	g_client = 1;
}

void	end_handler(int signal)
{
	(void)signal;
	ft_printf("MESSAGE RECEIVED :)");
	exit(EXIT_SUCCESS);
}

void	send_char(char c, __pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0b10000000 >> bit))
			safe_kill(server, SIGUSR1);
		else
			safe_kill(server, SIGUSR2);
		while (g_client == 0)
			pause();
		g_client = 0;
		bit++;
		usleep(50);
	}
}

int	main(int ac, char **av)
{
	__pid_t	server;
	char	*msg;

	if (!check_input(ac, av))
		return (0);
	server = ft_atoi(av[1]);
	signal(SIGUSR1, ack_handler);
	signal(SIGUSR2, end_handler);
	msg = av[2];
	while (*msg)
		send_char(*msg++, server);
	send_char('\0', server);
}
