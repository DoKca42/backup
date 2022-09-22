/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queenv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@k0r3p2.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:21:07 by loculy            #+#    #+#             */
/*   Updated: 2022/09/10 14:45:48 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_print_queen(char c)
{
	printf("%c", c);
	//write(1, &c, 1);
}

int ft_diag(int val)
{
	if (val < 0)
		return (-val);
	else
		return (val);
}

void	ft_place(int *tab, int *totalpt, int col)
{
	int i;
	int c;

	if (col == 10)
	{
		col = 0;
		while (col < 10)
			ft_print_queen(tab[col++] + '0');
		ft_print_queen('\n');
		*totalpt += 1;
		return;
	}
	c = 0;
	while (c < 10)
	{
		i = 0;
		while (i < col && tab[i] != c && ft_diag(tab[i] - c) != ft_diag(i - col))
			i++;
		if (col <= c)
		{
			tab[col] = c;
			ft_place(tab ,totalpt, col + 1);
		}
		c++;
	}
}

int ft_ten_queens_puzzle(void)
{
	int total;
	int tab[10];
	int col;
	int *totalpt;

	col = 0;
	total = 0;
	totalpt = &total;
	ft_place(tab ,totalpt, col);
	return (total);
}
int main()
{
	printf("%d",  ft_ten_queens_puzzle());
    return (0);
}