/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:53:38 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/23 22:00:24 by jrafols-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_str_trim(char *str);

struct s_numbers
{
	char	*key;
	char	*value;
};

unsigned int	size_dict(char *dict_path)
{
	int				file;
	unsigned int	size;
	char			str;

	size = 0;
	file = open(dict_path, O_RDONLY);
	if (file == -1)
		return (0);
	while (read(file, &str, 1))
	{
		if (str == '\n')
			size++;
	}
	close(file);
	return (size);
}

int	ft_param_end(char str, int *status)
{
	if (str == ':')
	{
		*status = 2;
		return (1);
	}
	else if (str == '\n')
	{
		*status = 1;
		return (1);
	}
	return (0);
}

char	*ft_read_param(int file, unsigned int *reading, int *status)
{
	char			*param;
	char			str;
	unsigned int	i;

	param = malloc(30 * sizeof(char));
	if (!param)
	{
		*status = -1;
		return (param);
	}
	i = 0;
	while (*reading && i < 29)
	{
		*reading = read(file, &str, 1);
		if (ft_param_end(str, status))
			break ;
		param[i] = str;
		i++;
	}
	param[i + 1] = '\0';
	return (ft_str_trim(param));
}

// Stores a 2d Array in mdict provided a path to a .dict file
// if the path is not valid, it errors and returns false (0)
unsigned int	ft_save_memory(struct s_numbers *dict, char *dict_path)
{
	int				file;
	int				saved;
	unsigned int	reading;
	unsigned int	i;

	file = open (dict_path, O_RDONLY);
	if (file == -1)
		return (0);
	reading = 1;
	saved = 1;
	i = 0;
	while (reading)
	{
		if (saved == 1)
			dict[i].key = ft_read_param(file, &reading, &saved);
		if (saved == 2)
		{
			dict[i].value = ft_read_param(file, &reading, &saved);
			i++;
		}
		if (!saved)
			return (0);
	}
	close (file);
	return (1);
}

struct s_numbers	*ft_parse_dict(unsigned int *size, char *dict_path)
{
	struct s_numbers	*mat;

	*size = size_dict(dict_path);
	mat = (struct s_numbers *) malloc(*size * sizeof(struct s_numbers));
	if (!ft_save_memory(mat, dict_path) || !mat)
		return (mat);
	return (mat);
}
