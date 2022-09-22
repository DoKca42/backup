/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_standard_input2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:13:25 by lloison           #+#    #+#             */
/*   Updated: 2022/09/21 15:58:19 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_functional.h"

int	r_verify_first_line(char *buf, char *valid_chars)
{
	int		i;
	int		length;
	char	temp;

	i = 0;
	length = ft_strlen(buf);
	if (length < 4)
		return (-1);
	if (buf[length - 1] < 32 || buf[length - 1] > 126
		|| buf[length - 2] < 32 || buf[length - 2] > 126
		|| buf[length - 3] < 32 || buf[length - 3] > 126)
		return (-1);
	valid_chars[1] = buf[length - 2];
	valid_chars[0] = buf[length - 3];
	temp = buf[length - 3];
	buf[length - 3] = '\0';
	if (ft_str_is_numeric(buf) == -1 || ft_atoi(buf) == 0)
		return (-1);
	if (valid_chars[0] == valid_chars[1] || valid_chars[0] == buf[length - 1]
		|| valid_chars[1] == buf[length - 1])
		return (-1);
	buf[length - 3] = temp;
	return (0);
}
