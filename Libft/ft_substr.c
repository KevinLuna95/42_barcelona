/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:32:53 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/09/25 17:32:45 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libc.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	c_src;
	size_t	c_dst;

	c_src = 0;
	c_dst = 0;
	while (src[c_src])
		c_src++;
	if (!dstsize)
		return (c_src);
	while (c_dst < (dstsize -1) && c_dst + 1 <= c_src)
	{
		dst[c_dst] = src[c_dst];
		c_dst++;
	}
	dst[c_dst] = '\0';
	return (c_src);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	c;
	char			*res;

	c = 0;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res || !s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s) || !ft_strlcpy(res, s + start, len + 1))
		res[0] = '\0';
	return (res);
}
/*
int	main(void)
{
	char	*str = "Hola soy Kevin";
	char	*sub;

	sub = ft_substr(str, 9, 14);
	printf("%s\n", sub);
	free(sub);
	return (0);
}
*/
