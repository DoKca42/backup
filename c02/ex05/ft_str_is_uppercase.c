/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:51:17 by loculy            #+#    #+#             */
/*   Updated: 2022/09/02 10:53:41 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int		alpha;
	int		i;
	char	a;

	alpha = 1;
	i = 0;
	while (str[i])
	{
		a = str[i];
		if (!(a >= 'A' && a <= 'Z'))
		{
			alpha = 0;
		}
		i++;
	}
	return (alpha);
}
