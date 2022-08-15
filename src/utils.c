/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 09:23:32 by pniezen       #+#    #+#                 */
/*   Updated: 2022/03/22 09:51:38 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <limits.h>

int	check_for_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			exit_on_wrong_pid();
		i++;
	}
	return (1);
}

int	parse_pid(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("The PID you gave is not a valid number\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_putstr_fd("The PID you gave is not a valid number\n", 2);
		exit(EXIT_FAILURE);
	}
	return (num);
}
