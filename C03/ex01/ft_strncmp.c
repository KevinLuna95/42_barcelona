/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:27:08 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/20 18:58:31 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;

	count = -1;
	while ((s1[++count] || s2[count]) && count < n)
	{
		if (s1[count] != s2[count])
			return (s1[count] - s2[count]);
	}
	return (0);
}
/*
int main() {
    char s1[] = "hola";
    char s2[] = "holA";

    printf("%i \n", ft_strncmp(s1, s2, 4));

  return 0;
}*/
