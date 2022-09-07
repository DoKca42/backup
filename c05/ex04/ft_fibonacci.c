/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:56:24 by loculy            #+#    #+#             */
/*   Updated: 2022/09/07 11:56:29 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_fibonacci_calc(int index, int pose, int res, int somme[3])
{
	if (pose < index)
	{
		res = somme[0] + somme[1];
		pose++;
		somme[0] = somme[1];
		somme[1] = res;
		res = ft_fibonacci_calc(index, pose, res, somme);
	}

	return (res);
}

int	ft_fibonacci(int index)
{
	int res;
	int somme[3];
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	somme[0] = 0;
	somme[1] = 1;
	res = ft_fibonacci_calc(index, 1, res, somme);
	return (res);
}
