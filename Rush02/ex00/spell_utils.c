/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:02:46 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/23 23:20:17 by jrafols-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

struct s_numbers
{
	char	*key;
	char	*value;
};

unsigned int	ft_num_name(unsigned int key, struct s_numbers *dict,
					unsigned int size, unsigned int space);
unsigned int	ft_get_magnitude(unsigned int num);
unsigned int	ft_power(unsigned int n, unsigned int power);

void	ft_write(char *str, int len)
{
	int	file;

	file = open("result_buffer.txt",
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	write(file, str, len);
	close(file);
}

unsigned int	ft_spell_tens(unsigned int num, unsigned int size,
					unsigned int index, struct s_numbers *dict)
{
	unsigned int	digit;
	unsigned int	magnitude;

	magnitude = ft_get_magnitude(num) - index;
	digit = (num / ft_power(10, magnitude - 1)) % 10;
	if (!((num / ft_power(10, magnitude))) % 10 && index)
		ft_write(" and", 4);
	if (digit < 2)
	{
		digit = (num / ft_power(10, magnitude - 2)) % 100;
		if (ft_num_name(digit, dict, size, index))
			return (2);
		return (0);
	}
	return (ft_num_name(digit * 10, dict, size, index));
}

void	ft_clear_buffer_file(void)
{
	int	file;

	file = open("result_buffer.txt",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	close(file);
}
