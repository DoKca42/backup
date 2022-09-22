/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:46:16 by loculy            #+#    #+#             */
/*   Updated: 2022/09/02 10:50:34 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int		alpha;
	int		i;
	char	a;

	alpha = 1;
	i = 0;
	while (str[i])
	{
		a = str[i];
		if (!(a >= 'a' && a <= 'z'))
		{
			alpha = 0;
		}
		i++;
	}
	return (alpha);
}
