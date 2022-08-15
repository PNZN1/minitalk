/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 15:49:43 by pniezen       #+#    #+#                 */
/*   Updated: 2022/03/22 09:51:59 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libft.h"
# include <signal.h>

int		check_for_digit(char *s);
int		parse_pid(char *str);

void	exit_on_less_arg(void);
void	exit_on_wrong_pid(void);
void	exit_on_server_error(void);
void	exit_on_client_error(void);

#endif
