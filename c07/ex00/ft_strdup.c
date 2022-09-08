/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:09:36 by loculy            #+#    #+#             */
/*   Updated: 2022/09/08 18:09:40 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlenloc(char *src)
{
	int i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*m;
	int		i;
	int		sizesrc;

	i = 0;
	sizesrc = ft_strlenloc(src);
	m = (char *)malloc(sizesrc * sizeof(char) + 1);
	if (m == 0)
		return (0);
	while (i < sizesrc)
	{
		m[i] = src[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}
