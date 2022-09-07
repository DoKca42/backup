/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:05:32 by loculy            #+#    #+#             */
/*   Updated: 2022/09/02 13:52:39 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_ifcapital(char test)
{
	int		boolean;

	boolean = 0;
	if (test >= 'A' && test <= 'Z' || test >= 'a' && test <= 'z')
	{
		boolean = 1;
	}
	else if (test >= '0' && test < '9')
	{
		boolean = 1;
	}
	return (boolean);
}

void	ft_upcapital(char *str, int i)
{
	char	c_actual;
	char	c_av;
	char	c_ap;

	c_actual = str[i];
	c_ap = str[i + 1];
	
	if (c_actual >= 'a' && c_actual <= 'z')
	{
		if (ft_ifcapital(c_ap) == 1)
		{
			if (i == 0)
			{
				str[i] = str[i] - 32;
			}
			else
			{
				c_av = str[i - 1];
				if (ft_ifcapital(c_av) == 0)
				{
					str[i] = str[i] - 32;
				}
			}
		}
	}
}

void	ft_lowcapital(char *str, int i)
{
	char	c_actual;
	char	c_av;
	char	c_ap;

	c_actual = str[i];
	c_av = str[i - 1];
	if (c_actual >= 'A' && c_actual <= 'Z')
	{
		if (i != 0)
		{
			if (ft_ifcapital(c_av) == 1)
			{
				str[i] = str[i] + 32;
			}
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_lowcapital(str, i);
		ft_upcapital(str, i);
		i++;
	}
	return (str);
}
