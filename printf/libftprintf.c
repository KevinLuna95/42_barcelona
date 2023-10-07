/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:05:24 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/10/07 22:32:02 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_cspdiuxx(char c, va_list params)
{
	if (c == 'c')
		return (ft_putchar_len(va_arg(params, int)));
	if (c == 's')
		return (ft_putstr_len(va_arg(params, char *)));
	if (c == 'p')
		return (ft_putstr_len("0x") + ft_putnbr_base(
				va_arg(params, unsigned long), "0123456789abcdef"));
	if (c == 'd')
		return (ft_putnbr_base(va_arg(params, int), "0123456789"));
	if (c == 'i')
		return (ft_putnbr_base(va_arg(params, int), "0123456789"));
	if (c == 'u')
		return (ft_putnbr_base(va_arg(params, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(params, unsigned int),
				"0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(params, unsigned int),
				"0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar_len('%'));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		len;
	int		count;
	va_list	params;

	len = -1;
	count = 0;
	va_start(params, str);
	while (str[++len])
	{
		if (str[len] == '%')
		{
			len++;
			count += convert_cspdiuxx(str[len], params);
		}
		else
		{
			count++;
			ft_putchar_len(str[len]);
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
