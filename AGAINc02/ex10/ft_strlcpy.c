/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:49:31 by loculy            #+#    #+#             */
/*   Updated: 2022/09/03 17:49:49 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	a;
	int	i;

	i = 0;
	a = 0;
	while (src[i])
	{
		i++;
	}
	while (src[a] && (a < size - 1))
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (i);
}
