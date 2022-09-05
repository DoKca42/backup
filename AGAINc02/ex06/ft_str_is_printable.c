/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:13:41 by loculy            #+#    #+#             */
/*   Updated: 2022/09/02 12:20:43 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int		i;
	int		alpha;

	i = 0;
	alpha = 1;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] < 127))
		{
			alpha = 0;
		}
		i++;
	}
	return (alpha);
}
