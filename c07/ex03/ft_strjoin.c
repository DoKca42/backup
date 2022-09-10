/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:40:51 by loculy            #+#    #+#             */
/*   Updated: 2022/09/09 10:40:53 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_malloc_length_sep(int size, char *sep)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (sep[i])
		i++;
	res = i * (size - 1);
	return (res);
}

int	ft_malloc_length_src(int size, char **strs)
{
	int		i;
	int		a;
	int		res;
	char	*w;

	i = 0;
	a = 0;
	res = 0;
	while (i < size)
	{
		a = 0;
		w = strs[i];
		while (w[a])
			a++;
		res += a;
		i++;
	}
	return (res);
}

char	*ft_loop_join(char	*m, int res, char **strs, char *sep)
{
	int		b;
	char	*w;
	int		i;
	int		a;

	b = 0;
	i = 0;
	while (i < res)
	{
		a = 0;
		w = strs[b];
		while (w[a])
			m[i++] = w[a++];
		a = 0;
		while (sep[a] && i < res)
			m[i++] = sep[a++];
		b += 1;
	}
	return (m);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*m;
	int		res;

	res = 0;
	res = ft_malloc_length_src(size, strs);
	res += ft_malloc_length_sep(size, sep);
	m = malloc(res * sizeof(char));
	m = ft_loop_join(m, res, strs, sep);
	return (m);
}
