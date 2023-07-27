/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:52:51 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/26 10:24:48 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	count_argv;

	count_argv = -1;
	while (--argc >= 1)
	{
		while (argv[argc][++count_argv])
			write(1, &argv[argc][count_argv], 1);
		write(1, "\n", 1);
		count_argv = -1;
	}
}
