/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:13:01 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/19 10:04:33 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_strcat(char *dest, char *src)
{
	int	count_src;
	int	count_dest;

	count_src = 0;
	count_dest = 0;
	while (dest[count_dest] != '\0')
		count_dest++;
	while (src[count_src] != '\0')
	{
		dest[count_dest] = src[count_src];
		count_src++;
		count_dest++;
	}
	dest[count_dest] = '\0';
	return (dest);
}

/*int main() {
  char s1[] = "hoLa";
  char s2[] = "hola";
  
  printf("%s", ft_strcat(s1, s2));
  return 0;
}*/
