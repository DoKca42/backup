/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:26:21 by loculy            #+#    #+#             */
/*   Updated: 2022/09/07 20:26:24 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 0;
	if (argc != 0)
	{
		str = argv[0];
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	
	return (0);
}
