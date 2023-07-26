/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:16:27 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/18 16:34:54 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	count_src;

	count_src = 0;
	count = 0;
	while (src[count] != '\0')
	{
		if (count < size)
		{
			dest[count] = src[count];
			count++;
		}
		count_src++;
	}
	while (count < size)
	{
		dest[count] = '\0';
		count++;
	}
	return (count_src);
}
