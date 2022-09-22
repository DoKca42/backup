/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:41:31 by loculy            #+#    #+#             */
/*   Updated: 2022/09/22 10:41:31 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_calc_atoi(char *str, int i, int neg)
{
	int	res;

	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		res = -res;
	return (res);
}

int	ft_checkstart_atoi(char *str, int i)
{
	int		neg;
	char	c;

	neg = 0;
	c = str[i];
	while (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		i++;
		c = str[i];
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			if (neg == 0)
				neg = 1;
			else
				neg = 0;
		}
		i++;
	}
	return (ft_calc_atoi(str, i, neg));
}

int	ft_atoi(char *str)
{
	int		i;

	i = 0;
	return (ft_checkstart_atoi(str, i));
}
