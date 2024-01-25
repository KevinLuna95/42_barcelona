/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:05:24 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/11/13 08:18:30 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_cspdiuxx(char c, va_list params)
{
	if (c == 'c')
		return (ft_putchar_len(va_arg(params, int)));
	if (c == 's')
		return (ft_putstr_len(va_arg(params, char *)));
	if (c == 'p')
		return (ft_putnbr_base(
				va_arg(params, unsigned long), "0123456789abcdef", 1));
	if (c == 'd')
		return (ft_putnbr_base(va_arg(params, int), "0123456789", 0));
	if (c == 'i')
		return (ft_putnbr_base(va_arg(params, int), "0123456789", 0));
	if (c == 'u')
		return (ft_putnbr_base(va_arg(params, unsigned int), "0123456789", 0));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(params, unsigned int),
				"0123456789abcdef", 0));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(params, unsigned int),
				"0123456789ABCDEF", 0));
	if (c == '%')
		return (ft_putchar_len('%'));
	return (0);
}

static void	init_vars(int *len, int *count, int n_len, int n_count)
{
	*len = n_len;
	*count = n_count;
}

int	ft_printf(char const *str, ...)
{
	int		len;
	int		count;
	int		tmp;
	va_list	params;

	init_vars(&len, &count, -1, 0);
	va_start(params, str);
	while (str[++len])
	{
		if (str[len] == '%')
		{
			tmp = convert_cspdiuxx(str[++len], params);
			if (tmp == -1)
				return (-1);
			count += tmp;
		}
		else
		{
			count++;
			if (ft_putchar_len(str[len]) == -1)
				return (-1);
		}
	}
	va_end(params);
	return (count);
}

/*
int	main(void)
{
	char *str1 = "hola";
	char *str2 = "adios";
	char *str3 = "rol";

	printf("test de c:\n");
	printf("%i\n", ft_printf("%s\n", (char *)NULL));
	printf("%i\n", printf("%s\n", (char *)NULL));

	printf("test de c:\n");
	printf("%i\n", ft_printf("%c,%c,%c,%c,%c,%c,%c,%c\n",
			'a', 'z', '/', ' ', '\0', '0', '\e', '-'));
	printf("%i\n", printf("%c,%c,%c,%c,%c,%c,%c,%c\n",
			'a', 'z', '/', ' ', '\0', '0', '\e', '-'));
	printf("\ntest de s:\n");
	printf("%i\n", ft_printf("%s,%s,%s,%s,%s,%s\n",
			"hola", "^&#$%,%%,%c", "", "\t\\\v", " ", "'kk'"));
	printf("%i\n", printf("%s,%s,%s,%s,%s,%s\n",
			"hola", "^&#$%,%%,%c", "", "\t\\\v", " ", "'kk'"));
	printf("\ntest de p:\n");
	printf("%i\n", ft_printf("%p,%p,%p\n",
			str1, str2, str3));
	printf("%i\n", printf("%p,%p,%p\n",
			str1, str2, str3));
	printf("%i\n", ft_printf("%p", (void *)-1));
	printf("%i\n", printf("%p", (void *)-1));
	printf("\ntest de d:\n");
	printf("%i\n", ft_printf("%d,%d,%d,%d,%d,%d\n",
			0, 0.12, -2147483648, 2147483647, 9223372036854775807, 
			9223372036854775808));
	printf("%i\n", printf("%d,%d,%d,%d,%d,%d\n",
			0, 0.12, -2147483648, 2147483647, 9223372036854775807, 
			9223372036854775808));
	printf("\ntest de i:\n");
	printf("%i\n", ft_printf("%i,%i,%i,%i,%i,%i\n",
			0, 0.12, -2147483648, 2147483647, 9223372036854775807, 
			9223372036854775808));
	printf("%i\n", printf("%i,%i,%i,%i,%i,%i\n",
			0, 0.12, -2147483648, 2147483647, 9223372036854775807, 
			9223372036854775808));
	printf("\ntest de u:\n");
	printf("%i\n", ft_printf("%u,%u,%u,%u,%u,%u\n",
			0-1, 0.12, -2147483648, 2147483647, 9223372036854775807, 
			9223372036854775808));
	printf("%i\n", printf("%u,%u,%u,%u,%u,%u\n",
			0-1, 0.12, -2147483648, 2147483647, 9223372036854775807, 
			9223372036854775808));
	printf("\ntest de x:\n");
	printf("%i\n", ft_printf("%x,%x,%x,%x,%x,%x\n",
			0-1, 0.12, -2147483648, 2147483647, 9223372036854775807, 
			9223372036854775808));
	printf("%i\n", printf("%x,%x,%x,%x,%x,%x\n",
			0-1, 0.12, -2147483648, 2147483647, 9223372036854775807, 
			9223372036854775808));
	printf("\ntest de X:\n");
	printf("%i\n", ft_printf("%X,%X,%X,%X,%X,%X\n",
			0-1, 0.12, -2147483648, 2147483647, 9223372036854775807, 
			9223372036854775808));
	printf("%i\n", printf("%X,%X,%X,%X,%X,%X\n",
			0-1, 0.12, -2147483648, 2147483647, 9223372036854775807, 
			9223372036854775808));
	printf("\ntest de %% y otros:\n");
	printf("%i\n", ft_printf("hola\vesto\\es*una%%prueba\n",
			0-1, 0.12, -2147483648, 2147483647, 9223372036854775807, 
			9223372036854775808));
	printf("%i\n", printf("hola\vesto\\es*una%%prueba\n",
			0-1, 0.12, -2147483648, 2147483647, 9223372036854775807, 
			9223372036854775808));
	
			
	return (0);
}
*/
