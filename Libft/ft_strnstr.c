/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:59:30 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/09/25 02:55:04 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

typedef struct s_var {
	size_t	c_big;
	size_t	c_lit;
	size_t	flag;
}	t_var;

static void	var_zero(t_var *var, size_t c_big, size_t c_lit, size_t flag)
{
	var->c_big = c_big;
	var->c_lit = c_lit;
	var->flag = flag;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	t_var	var;

	var.c_big = -1;
	var.c_lit = 0;
	if (!*needle)
		return ((char *)&haystack[0]);
	while (haystack[++var.c_big] || var.c_big < len)
	{
		if (haystack[var.c_big] == needle[var.c_lit])
		{
			var.flag = 1;
			while (needle[var.c_lit] && var.flag && (var.c_big < len))
			{
				if (haystack[var.c_big++] != needle[var.c_lit++])
					var_zero(&var, var.c_big, 0, 0);
				if (var.flag && !needle[var.c_lit])
					return ((char *)&haystack[var.c_big - var.c_lit]);
			}
		}
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("ft: %s\n", ft_strnstr("Hola soy Kevin", "", 5));
	printf("or: %s\n", strnstr("Hola soy Kevin", "", 5));
	printf("ft: %s\n", ft_strnstr("soja soya sota", "soy", 15));
	printf("or: %s\n", strnstr("soja soya sota", "soy", 15));
	printf("ft: %s\n", ft_strnstr("Hola soy Kevin", "bueno", 10));
	printf("or: %s\n", strnstr("Hola soy Kevin", "bueno", 10));
	printf("ft: %s\n", ft_strnstr("Hola soy Kevin", "a ", 5));
	printf("or: %s\n", strnstr("Hola soy Kevin", "a ", 5));
	printf("ft: %s\n", ft_strnstr("Hola soy Kevin", "Hola", 10));
	printf("or: %s\n", strnstr("Hola soy Kevin", "Hola", 10));
	printf("ft: %s\n", ft_strnstr("Hola soy Kevin", "Kevin", 10));
	printf("or: %s\n", strnstr("Hola soy Kevin", "Kevin", 10));
	return (0);
}
*/
