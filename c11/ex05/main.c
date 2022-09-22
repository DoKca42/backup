/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:25:11 by loculy            #+#    #+#             */
/*   Updated: 2022/09/22 10:25:11 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/doop.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

void	calc(int a, int b, char op)
{
	int	res;

	if (op == '+')
		res = plus(a, b);
	else if (op == '-')
		res = moin(a, b);
	else if (op == '/')
		res = div(a, b);
	else if (op == '*')
		res = multi(a, b);
	else
		res = modulo(a, b);
	ft_putnbr(res);
}

int	checkerr(int a, int b, char op)
{
	if (a == 0 || b == 0)
	{
		if (op == '/')
			write(1, "Stop : division by zero\n", 24);
		else
			write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc == 4)
	{
		if (argv[3] == '+' || argv[3] == '-' || argv[3] == '/'
			|| argv[3] == '*' || argv[3] == '%')
		{
			a = ft_atoi(argv[1]);
			b = ft_atoi(argv[3]);
			if (argv[3] == '/' && argv[3] == '%')
			{
				if (checkerr(a, b) == 1)
					calc(a, b, argv[3]);
			}
		}
		else
			write(1, "0\n", 2);
	}
	return (0);
}
