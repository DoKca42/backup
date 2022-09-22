/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:51:38 by rficht            #+#    #+#             */
/*   Updated: 2022/09/03 15:51:41 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

void	rush(int x, int y );

void	print(int pos_x, int pos_y, int x, int y);

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	y_pos;
	int	x_pos;

	x_pos = 1;
	y_pos = 1;
	while (y_pos != y + 1)
	{
		print(x_pos, y_pos, x, y);
		if (x_pos != x)
			x_pos++;
		else
		{
			x_pos = 1;
			y_pos++;
			ft_putchar('\n');
		}
	}
}

void	print(int x_pos, int y_pos, int x, int y)
{
	if (y_pos == 1)
	{
		if (x_pos == 1 || x_pos == x)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else if (y_pos == y)
	{
		if (x_pos == 1 || x_pos == x)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (x_pos == 1 || x_pos == x)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}	
}
