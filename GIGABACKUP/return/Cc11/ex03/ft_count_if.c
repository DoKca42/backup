/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:25:34 by loculy            #+#    #+#             */
/*   Updated: 2022/09/21 19:25:34 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			nbr++;
		i++;
	}
	return (nbr);
}
