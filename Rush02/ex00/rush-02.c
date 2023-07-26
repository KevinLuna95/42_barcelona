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
#include <fcntl.h>
#include <unistd.h>

struct s_numbers	*ft_parse_dict(unsigned int *size, 
						char *dict_path);
void				ft_error(unsigned int code);
unsigned int		ft_atoi(char *str);
unsigned int		ft_spell(struct s_numbers *dict,
						unsigned int num, unsigned int size);
void				ft_clear_buffer_file(void);

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

void	ft_free(struct s_numbers *dict, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free((char *) dict[i].key);
		free((char *) dict[i].value);
		i++;
	}
	free(dict);
}

void	ft_write_out(void)
{
	char	str;
	int		file;
	int		last_space;

	file = open("result_buffer.txt", O_RDONLY);
	last_space = 1;
	while (read(file, &str, 1))
	{
		if (str != ' ' || !last_space)
			write(1, &str, 1);
		if (str == ' ')
			last_space = 1;
		else
			last_space = 0;
	}
	close(file);
}

// Handle parsing dict and start writing the number
void	ft_converter(char *num, char *dict_path)
{
	struct s_numbers	*dict;
	unsigned int		size;
	int					errored;

	errored = 0;
	dict = ft_parse_dict(&size, dict_path);
	ft_clear_buffer_file();
	if (!size || !dict)
	{
		ft_error(1);
		return ;
	}
	if (!ft_spell(dict, ft_atoi(num), size))
	{
		errored = 1;
		ft_error(1);
	}
	if (!errored)
		ft_write_out();
	ft_free(dict, size);
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
