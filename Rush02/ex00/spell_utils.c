/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:02:46 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/23 21:46:24 by jrafols-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

struct s_numbers
{
	char	*key;
	char	*value;
};

unsigned int	ft_num_name(unsigned int key, struct s_numbers *dict,
					unsigned int size, unsigned int space);
unsigned int	ft_get_magnitude(unsigned int num);
unsigned int	ft_power(unsigned int n, unsigned int power);

unsigned int	ft_spell_tens(unsigned int num, unsigned int size,
					unsigned int index, struct s_numbers *dict)
{
	unsigned int	digit;
	unsigned int	magnitude;

	magnitude = ft_get_magnitude(num) - index;
	digit = (num / ft_power(10, magnitude - 1)) % 10;
	if (!((num / ft_power(10, magnitude))) % 10 && index)
		write(1, " and", 4);
	if (digit < 2)
	{
		digit = (num / ft_power(10, magnitude - 2)) % 100;
		if (!ft_num_name(digit, dict, size, index))
			return (2);
		return (0);
	}
	return (ft_num_name(digit * 10, dict, size, index));
}
