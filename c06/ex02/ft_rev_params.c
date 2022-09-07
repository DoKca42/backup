/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:46:06 by loculy            #+#    #+#             */
/*   Updated: 2022/09/07 20:46:08 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		a;
	char	*str;

	a = argc - 1;
	while (a > 0)
	{
		i = 0;
		str = argv[a];
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		write(1, "\n", 1);
		a--;
	}
	return (0);
}
