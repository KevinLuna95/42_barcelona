/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:33:23 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/17 17:35:24 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char str)
{
	if (!(str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z'))
		return (0);
	return (1);
}

int	st_str_is_symbol(char str)
{
	if ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z')
		|| (str >= '0' && str <= '9'))
		return (0);
	return (1);
}

char	*ft_strlowercase(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] >= 'A' && str[count] <= 'Z')
			str[count] = str[count] + 32;
		count++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	count;

	count = 0;
	ft_strlowercase (str);
	while (str[count] != '\0')
	{
		if (ft_str_is_alpha (str[count]) == 1
			&& st_str_is_symbol (str[count -1]) == 1)
			str[count] -= 32;
		count++;
	}
	return (str);
}
