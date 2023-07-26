/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:59:07 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/20 18:55:38 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <libc.h>
//#include <stdio.h>
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	count;
	unsigned int	count_src;

	count_src = 0;
	count = 0;
	while (dest[count] != '\0')
		count++;
	while (count_src < nb && src[count_src] != '\0')
	{
		dest[count] = src[count_src];
		count++;
		count_src++;
	}
	dest[count] = '\0';
	return (dest);
}
/*
int main() {
  char s1[10] = "hoLa";
  char s2[] = "hola";

  printf("%s\n", ft_strncat(s1, s2, 3));
 // printf("%s\n", strncat(s1, s2, 3));
  return 0;
}*/
