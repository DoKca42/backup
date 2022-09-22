/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:09:45 by loculy            #+#    #+#             */
/*   Updated: 2022/09/03 18:09:50 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*basehex;
	unsigned char	*w;

	w = (unsigned char *)str;
	i = 0;
	basehex = "0123456789abcdef";
	while (str[i])
	{
		printf(" | %d", str[i]);
		//w = (unsigned char)str[i];
		printf(" | %d = ", w[i]);
		if (!(w[i] >= 32 && w[i] < 127))
		{
			ft_putchar('\\');
			ft_putchar(basehex[w[i] / 16]);
			ft_putchar(basehex[w[i] % 16]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		printf("\n");
		i++;
	}
}
