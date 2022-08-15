/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:54:50 by pniezen       #+#    #+#                 */
/*   Updated: 2022/04/15 09:57:32 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

static void	print_pid(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

static void	handle_message(int signum, siginfo_t *siginfo, void *context)
{
	static int				count = 8;
	static unsigned char	val = '\0';

	(void)context;
	val <<= 1;
	if (signum == 30)
		val |= 0;
	else if (signum == 31)
		val |= 1;
	count--;
	if (count == 0)
	{
		ft_putchar_fd(val, 1);
		val = '\0';
		count = 8;
		kill(siginfo->si_pid, SIGUSR1);
	}
	else
		kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	new_handler;
	struct sigaction	old_handler;

	print_pid();
	new_handler.sa_sigaction = &handle_message;
	sigemptyset(&new_handler.sa_mask);
	new_handler.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigaction(SIGUSR1, NULL, &old_handler);
	if (old_handler.sa_handler != SIG_IGN)
		sigaction(SIGUSR2, &new_handler, NULL);
	sigaction(SIGUSR2, NULL, &old_handler);
	if (old_handler.sa_handler != SIG_IGN)
		sigaction(SIGUSR1, &new_handler, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
