/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:09:24 by loculy            #+#    #+#             */
/*   Updated: 2022/09/14 11:09:24 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_stock_str.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}	
		ft_putchar(nb % 10 + '0');
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	a;

	a = 0;
	while (par[a].str)
	{
		ft_putstr(par[a].str);
		ft_putchar('\n');
		ft_putnbr(par[a].size);
		ft_putchar('\n');
		ft_putstr(par[a].copy);
		ft_putchar('\n');
		a++;
	}
}
