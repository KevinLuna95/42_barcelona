/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:39:15 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/23 21:43:08 by jrafols-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_numbers	*ft_parse_dict(unsigned int *size, 
						char *dict_path);
void				ft_error(unsigned int code);
unsigned int		ft_atoi(char *str);
unsigned int		ft_spell(struct s_numbers *dict,
						unsigned int num, unsigned int size);

struct s_numbers
{
	char	*key;
	char	*value;
};

int	validate_arg(char *str)
{
	int	count;

	count = -1;
	while (str[++count])
	{
		if (!(str[count] >= '0' && str[count] <= '9'))
			return (0);
	}
	return (1);
}

// Handle parsing dict and start writing the number
void	ft_converter(char *num, char *dict_path)
{
	struct s_numbers	*dict;
	unsigned int		size;
	unsigned int		i;

	dict = ft_parse_dict(&size, dict_path);
	if (!size || !dict)
	{
		ft_error(1);
		return ;
	}
	if (!ft_spell(dict, ft_atoi(num), size))
		ft_error(1);
	i = 0;
	while (i < size)
	{
		free((char *) dict[i].key);
		free((char *) dict[i].value);
		i++;
	}
	free(dict);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (validate_arg(argv[1]))
			ft_converter(argv[1], "numbers.dict");
		else
			ft_error(0);
	}
	else if (argc == 3)
	{
		if (validate_arg(argv[2]))
			ft_converter(argv[2], argv[1]);
		else
			ft_error(0);
	}
	else
		ft_error(0);
	return (0);
}
