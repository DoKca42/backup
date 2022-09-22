/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:56:59 by loculy            #+#    #+#             */
/*   Updated: 2022/09/12 12:40:47 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_res_size(long nbr, int size);
char	*ft_convert_base_to(long nbr, char *base_to, int sizeto, char *m);

char	*ft_null(char	*base_to)
{
	char	*ret;

	ret = malloc (2 * sizeof(char));
	ret[0] = base_to[0];
	ret[1] = 0;
	return (ret);
}

long	ft_conv_atoi(char *str, int i, char *base, int size)
{
	int		a;
	int		b;
	long	res;

	a = 0;
	b = 0;
	res = 0;
	while (str[b + i])
	{
		a = 0;
		while (base[a] && base[a] != str[b + i])
			a++;
		if (base[a] == str[b + i])
			res = res * size + a;
		else
			return (res);
		b++;
	}
	return (res);
}

long	ft_check_atb(char *str, int i, char *base, int size)
{
	int		neg;
	long	res;

	neg = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			if (neg == 0)
				neg = 1;
			else
				neg = 0;
		}
		i++;
	}
	res = ft_conv_atoi(str, i, base, size);
	if (neg == 1)
		res = -res;
	return (res);
}

int	ft_base_check(char *base)
{
	int	i;
	int	w;
	int	hash[129];
	int	o;

	i = 0;
	o = 0;
	while (o < 129)
		hash[o++] = 0;
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sizefrom;
	int		sizeto;
	long	b;
	char	*m;

	sizefrom = ft_base_check(base_from);
	sizeto = ft_base_check(base_to);
	if (sizefrom == 0 || sizeto == 0)
		return (0);
	b = ft_check_atb(nbr, 0, base_from, sizefrom);
	if (b == 0)
		return (ft_null(base_to));
	m = malloc(sizeof(char) * ft_res_size(b, sizeto) + 1);
	if (!m)
		return (0);
	m = ft_convert_base_to(b, base_to, sizeto, m);
	return (m);
}
