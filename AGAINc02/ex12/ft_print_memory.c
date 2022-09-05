/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:50:31 by loculy            #+#    #+#             */
/*   Updated: 2022/09/04 14:20:36 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_ch_m(char	*addr, int sz)
{
	int	i;

	i = 0;
	while (i < sz)
	{
		if (!(addr[i] >= 32 && addr[i] < 127))
			ft_putchar('.');
		else
			ft_putchar(addr[i]);
		i++;
	}
}

void	ft_pr_m(char hexarr[17], char *addr, int sz, int i)
{
	while (i < 17)
	{
		ft_putchar(hexarr[i]);
		i++;
	}
	write(1, ": ", 2);
	i = 0;
	while (i < 16)
	{
		if (i < sz)
		{
			ft_putchar("0123456789abcdef"[addr[i] / 16]);
			ft_putchar("0123456789abcdef"[addr[i] % 16]);
		}
		else
			write(1, "  ", 2);
		if (i % 2 != 0)
			ft_putchar(' ');
		i++;
	}
}

void	ft_hex_mem(unsigned long add, char	*addr, int sz, int i)
{
	char	*basehex;
	char	hexarr[17];

	basehex = "0123456789abcdef";
	i = 16;
	while (i > 0)
	{
		if (add >= 10)
		{
			hexarr[i] = basehex[add % 16];
			add = add / 16;
		}
		else
		{
			hexarr[i] = basehex[add];
			add = add - add;
		}
		i--;
	}
	ft_pr_m(hexarr, addr, sz, 1);
	ft_ch_m(addr, sz);
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*str;
	unsigned int	i;
	unsigned int	a;
	unsigned long	add;

	a = 0;
	str = addr;
	add = *((unsigned long *)&addr);
	while (str[a])
		a++;
	i = 0;
	if (a > size)
		a = size;
	while (i <= a)
	{
		if (a >= 16)
			ft_hex_mem(add + i * 16, addr + i * 16, 16, 0);
		else
			ft_hex_mem(add + i * 16, addr + i * 16, a, 0);
		a = a - 16;
		i++;
	}
	return (addr);
}
