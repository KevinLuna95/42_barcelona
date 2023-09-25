/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:28:52 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/09/23 18:54:21 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

const void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		count;
	const char	*cast_s;

	cast_s = (char *)s;
	count = -1;
	while (++count < n)
	{
		if (cast_s[count] == c)
			return ((char *)&s[count]);
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "Hola soy Kevin y me gusta el pollo frito";

	printf("%s\n", memchr(str, '3', 50));
	printf("%s\n", ft_memchr(str, '3', 50));
	return (0);
}
*/