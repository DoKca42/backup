/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:50:44 by loculy            #+#    #+#             */
/*   Updated: 2022/09/02 10:42:50 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int		alpha;
	int		i;
	char	a;

	alpha = 1;
	i = 0;
	while (str[i])
	{
		a = str[i];
		if (!(a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z'))
		{
			alpha = 0;
		}
		i++;
	}
	return (alpha);
}
