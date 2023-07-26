/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:37:35 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/20 20:07:42 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <libc.h>
//#include <stdio.h>
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	c_dest;
	unsigned int	c_src;
	unsigned int	res;

	c_dest = 0;
	c_src = 0;
	while (dest[c_dest])
		c_dest++;
	while (src[c_src])
		c_src++;
	res = c_src + c_dest;
	c_src = 0;
	while (c_dest < size -1 && src[c_src] != '\0')
	{
		dest[c_dest] = src[c_src];
		c_dest++;
		c_src++;
	}
	dest[c_dest] = '\0';
	return (res);
}
/*
int main ()
{
	char a[10] = "HOLA";
	char b[] = "holahola";

	printf("%lu\n", strlcat(a, b, 4));
	printf("%i\n", ft_strlcat(a, b, 10));
	printf("%s\n", a);

}*/
