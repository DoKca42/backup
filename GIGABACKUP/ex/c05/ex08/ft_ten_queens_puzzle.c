/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:21:07 by loculy            #+#    #+#             */
/*   Updated: 2022/09/10 11:21:09 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_queen(char c)
{
	write(1, &c, 1);
}

int	ft_diag(int tabi, int c, int i, int col)
{
	int	resa;
	int	resb;

	resa = tabi - c;
	resb = i - col;
	if (0 > resa)
		resa = -resa;
	if (0 > resb)
		resb = -resb;
	if (resa != resb)
		return (1);
	else
		return (0);
}

void	ft_place(int *tab, int *totalpt, int col)
{
	int	i;
	int	c;

	if (col == 10)
	{
		col = 0;
		while (col < 10)
			ft_print_queen(tab[col++] + '0');
		ft_print_queen('\n');
		*totalpt += 1;
		return ;
	}
	c = 0;
	while (c < 10)
	{
		i = 0;
		while (i < col && tab[i] != c && ft_diag(tab[i], c, i, col) == 1)
			i++;
		if (col <= i)
		{
			tab[col] = c;
			ft_place(tab, totalpt, col + 1);
		}
		c++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	total;
	int	tab[10];
	int	col;
	int	*totalpt;

	col = 0;
	total = 0;
	totalpt = &total;
	ft_place(tab, totalpt, col);
	return (total);
}
