/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:49:40 by loculy            #+#    #+#             */
/*   Updated: 2022/09/20 11:34:02 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_baseconvert(long int nb, char *base, int size)
{
	if (nb / size != 0)
		ft_baseconvert((nb / size), base, size);
	write(1, &base[nb % size], 1);
}

int	ft_base_good(char *base, int *hash)
{
	int	i;
	int	w;

	i = 0;
	while (base[i])
	{
		w = base[i];
		if (hash[w] != 1 && base[i] != '+' && base[i] != '-' && base[i] > 0)
			hash[w] = 1;
		else
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
		i++;
	if (i <= 1)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			size;
	int			hash[129];
	long int	nb;
	int			o;

	o = 0;
	while (o < 129)
		hash[o++] = 0;
	size = ft_base_good(base, hash);
	if (size != 0)
	{
		nb = (long int)nbr;
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		ft_baseconvert(nb, base, size);
	}
}
