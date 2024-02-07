/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:27:54 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/02/07 18:45:14 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"


static void	send_signal(const int pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	usleep(CALM);
}

static void	char_to_byte(const int pid, char ch)
{
	int	bite;

	bite = 7;
	while (bite >= 0)
	{
		if (((ch >> bite) & 1) == 1)
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
		bite--;
		usleep(CALM);
	}
}

static void	long_to_byte(const int pid, long num)
{
	int	bite;

	bite = 31;
	while (bite >= 0)
	{
		if (((num >> bite) & 1) == 1)
		{
			send_signal(pid, SIGUSR1);
		}
		else
		{
			send_signal(pid, SIGUSR2);
		}
		bite--;
		usleep(CALM);
	}
}

static void	err_pid(int pid)
{
	if (pid <= 0)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

//strlen delong, para asegurar que el input es correcto.
long	ft_long_strlen(char *str)
{
	long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc <= 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	else if (argc >= 4)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	err_pid(pid);
	i = 0;
	long_to_byte(pid, ft_long_strlen(argv[2]));
	while (argv[2][i])
	{
		char_to_byte(pid, argv[2][i]);
		i++;
	}
	return (0);
}
