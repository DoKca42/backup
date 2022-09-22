/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:18:43 by loculy            #+#    #+#             */
/*   Updated: 2022/09/01 12:05:37 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_bef_write(char nb_a, char nb_b)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = nb_a / 10 + '0';
	b = nb_a % 10 + '0';
	c = nb_b / 10 + '0';
	d = nb_b % 10 + '0';
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
	if (!(nb_a == 98 && nb_b == 99))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	char	nb_a;
	char	nb_b;

	nb_a = 0;
	while (nb_a < 99)
	{
		nb_b = nb_a + 1;
		while (nb_b <= 99)
		{
			ft_bef_write(nb_a, nb_b);
			nb_b++;
		}
		nb_a++;
	}
}
