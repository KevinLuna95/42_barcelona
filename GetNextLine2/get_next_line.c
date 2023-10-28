/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 07:48:29 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/10/29 00:42:40 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_nl(char *chunk)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (chunk[i] == '\n')
			return (i);
		if (chunk[i] == '\0')
		{
			if (i > 0)
				i--;
			return (i);
		}
		i++;
	}
	return (-1);
}

static char	*ft_strchr(const char *s, int c)
{
	int		count;

	count = -1;
	while (s[++count])
	{
		if (s[count] == (unsigned char)c)
			return ((char *)&s[count]);
	}
	if (s[count] == (unsigned char)c)
		return ((char *)&s[count]);
	else
		return (NULL);
}

static char	*get_next_line_two(char **line, char *chunk, int fd)
{
	*line = ft_strdup("");
	if (!*line)
		return (ft_free(*line));
	if (chunk[0] != '\0')
	{
		*line = ft_strjoin(*line, chunk, is_nl(chunk) + 1);
		if (!*line)
			return (ft_free(*line));
	}
	if (chunk[0] == '\0')
	{
		if (read(fd, chunk, BUFFER_SIZE) == -1)
			return (ft_free(*line));
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	chunk[BUFFER_SIZE];
	char		*line;

	if (fd < 0 && !(fd >= 0))
		return (NULL);
	if (!get_next_line_two(&line, chunk, fd))
		return (NULL);
	while (is_nl(chunk) == -1)
	{
		line = ft_strjoin(line, chunk, BUFFER_SIZE);
		if (!line)
			return (ft_free(line));
		if (read(fd, chunk, BUFFER_SIZE) == -1)
			return (ft_free(line));
	}
	if (chunk[0] != '\0' && !ft_strchr(line, '\n'))
		line = ft_strjoin(line, chunk, is_nl(chunk) + 1);
	if (!line || !line[0])
		return (ft_free(line));
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("file.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("MAIN::::|%s|", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 		printf("MAIN::::|%s|", line);
// 	close(fd);
// 	return (0);
// }
