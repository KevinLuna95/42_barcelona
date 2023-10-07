/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:17:39 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/10/07 21:56:03 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		ft_putstr_len(char *s);
int		ft_putnbr_base(long nbr, char *base);
void	rec_nb(long num, char *base, int size, int *len);
int		ft_putchar_len(char c);

#endif