/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:00:28 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/20 18:59:43 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_strcmp(char *s1, char *s2)
{
	int	count;

	count = -1;
	while (s1[++count] || s2[count])
	{
		if (s1[count] != s2[count])
			return (s1[count] - s2[count]);
	}
	return (0);
}
/*
int main() {
    char s1[] = "hola";
    char s2[] = "hola";

    printf("%i \n", ft_strcmp(s1, s2));
  return 0;
}*/
