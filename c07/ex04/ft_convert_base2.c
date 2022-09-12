/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:57:08 by loculy            #+#    #+#             */
/*   Updated: 2022/09/10 18:57:11 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_addtab(char c, char *m, int i)
{
	m[i] = c;
	return (i + 1);
}

void	ft_baseconvert(long nbr, char *base, int size, char *m)
{
	if (nbr > size)
		ft_baseconvert((nbr / size), base, size, m - 1);
	m[0] = base[nbr % size];
}

int	ft_res_size(long nbr, int size)
{
	int	res;

	res = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		res = 1;
	}
	while (nbr > size)
	{
		nbr = nbr / size;
		res += 1;
	}
	return (res);
}

char	*ft_convert_base_to(long nbr, char *base_to, int sizeto, char *m)
{	
	int	sizefn;

	sizefn = ft_res_size(nbr, sizeto);
	if (nbr < 0)
	{
		m[0] = '-';
		nbr = -nbr;
	}
	ft_baseconvert(nbr, base_to, sizeto, m + sizefn);
	m[sizefn + 1] = '\0';
	return (m);
}
