/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_msg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 08:48:51 by pniezen       #+#    #+#                 */
/*   Updated: 2022/03/22 09:32:06 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

void	exit_on_less_arg(void)
{
	ft_putstr_fd("\nPlease use like this:\n\n./client [PID] [\"message\"]\n\n", 2);
	exit(EXIT_FAILURE);
}

void	exit_on_wrong_pid(void)
{
	ft_putstr_fd("\nThe given PID is not a valid PID.\n", 1);
	exit(EXIT_FAILURE);
}

void	exit_on_server_error(void)
{
	ft_putstr_fd("Error on server side.\nIs it running?\n", 2);
	exit(EXIT_FAILURE);
}

void	exit_on_client_error(void)
{
	ft_putstr_fd("Error on client side.\nCould not set signal()\n", 2);
	exit(EXIT_FAILURE);
}
