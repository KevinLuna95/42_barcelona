/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:25:17 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/02/07 20:37:19 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

/*iter[0] = bite numbers, iter[1] = iterator*/

void	extra_len(int (*iter)[3], int sig, long *size, char **str)
{
	(*iter)[1] += 1;
	*size <<= 1;
	if (sig == SIGUSR1)
		*size |= 1;
	(*iter)[0] += 1;
	if ((*iter)[0] == 32)
	{
		(*iter)[0] = 0;
		(*iter)[1] = 0;
		(*iter)[2] = 0;
		*str = (char *)ft_calloc((*size + 1), sizeof(char));
		if (*str == NULL)
			ft_printf("Error\n"), exit(0);
	}
}

void	restart(int (*iter)[3], char *ch, long *size, long *pos)
{
		*size = 0;
		*ch = '\0';
		*iter[0] = 0;
		*iter[1] = 0;
		*iter[2] = 1;
		*pos = 0;
}

clean_str(char **str)
{
	int i;

	i = 0;

	while(str[i])
		str[i++] = 0;
}

static void	handler(int sig)
{
	static int				iter[3] = {0, 0, 1};
	static unsigned char	ch = '\0';
	static char				*str = NULL;
	static long				size = 0;
	static long				pos = 0;

	if (iter[2])
	{

		extra_len(&iter, sig, &size, &str);
		printf("en primer if: vars: iter[0] = %i, iter[1] = %i, iter[2] = %i, size = %ld, pos= %ld, ch= |%c|\n",iter[0], iter[1], iter[2], size, pos, ch);
	}
	else
	{
		printf("en else: vars: iter[0] = %i, iter[1] = %i, iter[2] = %i, size = %ld, pos= %ld, ch= |%c|\n",iter[0], iter[1], iter[2], size, pos, ch);

		ch <<= 1;
		if (sig == SIGUSR1)
			ch |= 1;
		iter[0]++;
		if (iter[0] == 8)
		{
			str[pos++] = ch;
			iter[0] = 0;
			ch = '\0';
		}
	}
	if (pos == size && size)
	{
		printf("en ultimo if: vars: iter[0] = %i, iter[1] = %i, iter[2] = %i, size = %ld, pos= %ld, ch= |%c|\n",iter[0], iter[1], iter[2], size, pos, ch);
		size = 0;
		restart(&iter, &ch, &size, &pos), ft_printf("%s\n", str);
		//printf("vars: iter[0] = %i, iter[1] = %i, iter[2] = %i, size = %ld, pos= %ld, ch= |%c|\n",iter[0], iter[1], iter[2], size, pos, ch);

	}
}


static void	ft_get_pid(void)
{
	int	pid;

	pid = getpid();
	if (!pid)
		write(2, "ERR", 3);
	ft_printf(" Pid: %i\n", pid);
}


static void	init(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	ft_get_pid();
	init();
	while (1)
		sleep(300);
	return (0);
}
