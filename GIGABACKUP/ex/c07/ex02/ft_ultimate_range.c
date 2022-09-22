/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:19:19 by loculy            #+#    #+#             */
/*   Updated: 2022/09/09 10:19:21 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*m;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	m = malloc((max - min) * sizeof(int));
	*range = m;
	if (!*range)
		return (-1);
	i = 0;
	while ((min + i) < max)
	{
		m[i] = min + i;
		i++;
	}
	return (i);
}
