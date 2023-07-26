/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:19:16 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/23 21:45:47 by jrafols-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

struct s_numbers
{
	char	*key;
	char	*value;
};

void			ft_error(unsigned int code);
unsigned int	ft_str_len(char *str);
unsigned int	ft_atoi(char *str);
unsigned int	ft_power(unsigned int n, unsigned int power);
unsigned int	ft_spell_tens(unsigned int num, unsigned int size,
					unsigned int index, struct s_numbers *dict);

// Prunsigned ints the name of a number given it's key.
// Returns 0 if the key is not in the loaded dict.
unsigned int	ft_num_name(unsigned int key, struct s_numbers *dict,
					unsigned int size, unsigned int space)
{
	unsigned int	i;

	i = 0;
	if (space)
		write(1, " ", 1);
	while (i < size)
	{
		if (key == ft_atoi(dict[i].key))
		{
			write(1, dict[i].value, ft_str_len(dict[i].value));
			return (1);
		}
		i++;
	}
	return (0);
}

// Count the magnitude of a number.
// i.e. Are we talking about millions, thousands, tens of thousands...
unsigned int	ft_get_magnitude(unsigned int num)
{
	unsigned int	magnitude;

	magnitude = 0;
	while (num)
	{
		magnitude++;
		num /= 10;
	}
	return (magnitude);
}

// Prunsigned int the name of the magnitude
// (thousand, million, billion...) if we are in
// the correct "digit index" and the magnitude is not 0.
//
// Return: true (1) if all OK, 0 if num couldn't be named.
unsigned int	ft_spell_magnitude(unsigned int num, unsigned int magnitude,
					struct s_numbers *dict, unsigned int size)
{
	unsigned int	check_magnitude;

	if (((magnitude - 1) % 3) || magnitude == 1)
		return (1);
	check_magnitude = magnitude;
	while (check_magnitude - magnitude < 3)
	{
		if ((num / ft_power(10, check_magnitude -1)) % 10)
		{
			return (ft_num_name(ft_power(10, magnitude - 1), dict, size, 1));
		}
		check_magnitude++;
	}
	return (1);
}

// Returns the amount of digits handled
// Examble: 17 handles 1 and 7 in the same "batch". So the next digit (7) should
// be skipped.
unsigned int	ft_spell_digit(unsigned int num, struct s_numbers *dict,
					unsigned int size, unsigned int index)
{
	unsigned int	digit;
	unsigned int	magnitude;

	magnitude = ft_get_magnitude(num) - index;
	digit = (num / ft_power(10, magnitude - 1)) % 10;
	if (digit == 0)
		return (1);
	if (magnitude % 3 == 1)
	{
		if (!((num / ft_power(10, magnitude)) % 10) && index)
			write(1, " and", 4);
		return (ft_num_name(digit, dict, size, index));
	}
	if (magnitude % 3 == 2)
		return (ft_spell_tens(num, size, index, dict));
	if (magnitude % 3 == 0)
	{
		if (index)
			write(1, " ", 1);
		ft_spell_digit(digit, dict, size, 0);
		return (ft_num_name(100, dict, size, 1));
	}
	return (1);
}

// Main function to handle writing out a number
// 1. Handle zero, because all zeros are ignored in deeper logic.
// 2. Cycle through each digit starting from the last (magnitude) and handle it.
//
// @unsigned int advanced: if we wited a two digit
// number e.g. 17, we want to advance
// two positions.
//
// Return: 0 if error. 1 if all OK.
unsigned int	ft_spell(struct s_numbers *dict, unsigned int num,
					unsigned int size)
{
	unsigned int	magnitude;
	unsigned int	advanced;
	unsigned int	i;

	if (num == 0)
		return (ft_num_name(num, dict, size, 0));
	magnitude = ft_get_magnitude(num);
	i = 0;
	while (magnitude)
	{
		advanced = ft_spell_digit(num, dict, size, i);
		if (!advanced)
			return (0);
		if (!ft_spell_magnitude(num, magnitude, dict, size))
			return (0);
		magnitude -= advanced;
		i++;
	}
	write(1, "\n", 1);
	return (1);
}
