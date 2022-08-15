/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 08:40:51 by pniezen       #+#    #+#                 */
/*   Updated: 2022/04/15 09:04:10 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

static int	g_done_waiting = 0;

static void	handler(int signum)
{
	if (signum == SIGUSR1)
		g_done_waiting = 1;
}

static void	send_message(unsigned int bite, int pid)
{
	unsigned int	b;

	b = 1 << 7;
	while (b)
	{
		g_done_waiting = 0;
		if (b & bite)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit_on_server_error();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit_on_server_error();
		}
		while (!g_done_waiting)
			;
		b >>= 1;
	}
}

static void	prepare_msg(int args, char **argv, int pid, int i)
{
	while (argv[args])
	{
		i = 0;
		if (ft_strnstr(argv[args], " ", ft_strlen(argv[args])))
		{
			while (argv[args][i])
			{
				send_message(argv[args][i], pid);
				i++;
			}
		}
		else
		{
			if (args > 2)
				send_message(' ', pid);
			while (argv[args][i])
			{
				send_message(argv[args][i], pid);
				i++;
			}
		}
		args++;
	}
	send_message('\n', pid);
}

int	main(int argc, char **argv)
{
	int	i;
	int	args;

	i = 0;
	args = 2;
	if (argc < 3 || (!check_for_digit(argv[1])))
		exit_on_less_arg();
	else if (!ft_strlen(argv[args]))
		exit_on_less_arg();
	else if (signal(SIGUSR1, handler) == SIG_ERR)
		exit_on_client_error();
	prepare_msg(args, argv, parse_pid(argv[1]), i);
	return (EXIT_SUCCESS);
}
