/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:12:46 by loculy            #+#    #+#             */
/*   Updated: 2022/09/08 19:12:48 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*m;

	if (min >= max)
		return (0);
	m = (int *)malloc((max - min) * sizeof(int));
	i = 0;
	while ((min + i) < max)
	{
		m[i] = min + i;
		i++;
	}
	return (m);
}
