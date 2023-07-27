/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:33:38 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/26 09:51:18 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	count_argc;
	int	count_argv;

	count_argc = 0;
	count_argv = -1;
	while (++count_argc < argc)
	{
		while (argv[count_argc][++count_argv])
			write(1, &argv[count_argc][count_argv], 1);
		write(1, "\n", 1);
		count_argv = -1;
	}
}
