/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:10:55 by loculy            #+#    #+#             */
/*   Updated: 2022/09/05 14:10:58 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_srctlen(char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	while (dest[a])
		a++;
	if (size == 0 || size <= a)
		return (size + ft_srctlen(src));
	while (src[b] && b < (size - a - 1))
	{
		dest[a + b] = src[b];
		b++;
	}
	dest[a + b] = '\0';
	return (a + ft_srctlen(src));
}
