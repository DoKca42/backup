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
	int			i;
	int			neg;
	char		*m;
	char		res[33];

	i = 0;
	neg = 0;
	if (nbr < 0)
	{
		neg = 1;
		nbr = -nbr;
	}
	while (nbr)
	{
		m[i++] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
	}
	if (neg == 1)
		ret[i++] = '-';
	m[i] = 0;
	ft_rev_int_tab(m, ft_strlen(m));
	m = ft_strdup(m);
	return (m);
}
