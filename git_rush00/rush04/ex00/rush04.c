/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarias <anarias@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:59:17 by anarias           #+#    #+#             */
/*   Updated: 2023/07/08 20:38:17 by anarias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char symbol);

void	print_first_row(int column, int count_column)
{
	if (count_column == 0)
	{
		ft_putchar('A');
	}
	else
	{
		if (count_column == column -1)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
}

void	print_last_row(int column, int count_column)
{
	if (count_column == 0)
	{
		ft_putchar('C');
	}
	else
	{
		if (count_column == column -1)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
}

void	print_row(int column, int count_column)
{
	if (count_column == 0)
	{
		ft_putchar('B');
	}
	else
	{
		if (count_column == column -1)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

void	print_matrix(int column, int row, int count_row, int count_column)
{
	if (count_row == 0)
	{
		print_first_row(column, count_column);
	}
	else
	{
		if (count_row == row -1)
			print_last_row(column, count_column);
		else
			print_row(column, count_column);
	}
}

void	rush(int column, int row)
{
	int	count_column;
	int	count_row;

	count_row = 0;
	count_column = 0;
	while (count_column < column && count_row < row)
	{
		print_matrix(column, row, count_row, count_column);
		count_column++;
		if (count_column == column && count_row < row)
		{
			count_column = 0;
			ft_putchar('\n');
			count_row++;
		}
	}
}
