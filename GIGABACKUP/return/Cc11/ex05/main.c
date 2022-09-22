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
#include "doop.h"

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

int	checkerr(int b, char op)
{
	if (b == 0)
	{
		if (op == '/')
			write(1, "Stop : division by zero", 23);
		else
			write(1, "Stop : modulo by zero", 21);
		return (0);
	}
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	op;

	op = argv[2][0];
	if (argc == 4)
	{
		if (op == '+' || op == '-' || op == '/'
			|| op == '*' || op == '%')
		{
			a = ft_atoi(argv[1]);
			b = ft_atoi(argv[3]);
			if (op == '/' || op == '%')
			{
				if (checkerr(b, op) == 1)
					calc(a, b, op);
			}
			else
				calc(a, b, op);
			write(1, "\n", 1);
		}
		else
			write(1, "0\n", 2);
	}
	return (0);
}
