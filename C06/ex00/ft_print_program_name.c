/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:01:45 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/27 12:01:10 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	count;

	count = -1;
	if (argc >= 1)
	{
		while (argv[0][++count])
			write(1, &argv[0][count], 1);
	}
	write (1, "\n", 1);
}
