/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:38:09 by loculy            #+#    #+#             */
/*   Updated: 2022/09/02 10:45:28 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int		alpha;
	int		i;
	char	a;

	alpha = 1;
	i = 0;
	while (str[i])
	{
		a = str[i];
		if (!(a >= '0' && a <= '9'))
		{
			alpha = 0;
		}
		i++;
	}
	return (alpha);
}
