/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:37:41 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/20 19:17:08 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <libc.h>
void	init_var(int *p_arr)
{
	p_arr[0] = 0;
	p_arr[1] = 0;
	p_arr[2] = 1;
}

void	check(int *p_arr, char *str, char *to_find)
{
	while (p_arr[2] && to_find[p_arr[1]] != '\0')
	{
		if (!(str[p_arr[0]] == to_find[p_arr[1]]))
			p_arr[2] = 0;
		p_arr[1]++;
		p_arr[0]++;
	}
	if (!p_arr[2])
	{
		p_arr[2] = 1;
		p_arr[1] = 0;
		p_arr[0] -= 2;
	}
	else
		p_arr[2] = 0;
}

char	*ft_strstr(char *str, char *to_find)
{
	int	arr[3];
	int	*p_arr;

	p_arr = arr;
	init_var(p_arr);
	while (arr[2] && str[arr[0]] != '\0')
	{
		if (str[arr[0]] == to_find[arr[1]])
		{
			check(p_arr, str, to_find);
		}
		arr[0]++;
	}
	if (arr[2])
		return ((char *)0);
	return (&str[arr[0] - arr[1] -1]);
}
/*
int main () {
   char haystack[] = "Tutorialsoint";
   char needle[] = "Point";
   char *ret;

   ret = ft_strstr(haystack, needle);

   printf("The substring is: %s\n", ret);

   ret = strstr(haystack, needle);

   printf("The substring is: %s\n", ret);

   return(0);
}*/
