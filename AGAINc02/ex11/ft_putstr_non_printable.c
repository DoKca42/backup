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
	unsigned char	w;

	i = 0;
	basehex = "0123456789abcdef";
	while (str[i])
	{
		w = str[i];
		if (!(w >= 32 && w < 127))
		{
			ft_putchar('\\');
			ft_putchar(basehex[w / 16]);
			ft_putchar(basehex[w % 16]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}
