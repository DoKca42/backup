/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorsmanage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:56:04 by loculy            #+#    #+#             */
/*   Updated: 2022/09/18 15:56:04 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_error_dict(int *error)
{
	if (*error == 0)
		write(1, "Dict Error\n", 11);
	*error = 1;
}

void	ft_error_in(int *error)
{
	if (*error == 0)
		write(1, "Error\n", 6);
	*error = 1;
}

void	ft_check_err(unsigned char *tab, int i, int *error, int size)
{
	if ((tab[i] != ':' && tab[i] != ' ') || size < 1)
		ft_error_dict(error);
}

struct s_dict	ft_check_i(int i, t_dict parse, int linek, int *error)
{
	if (i != 0 || parse.k != NULL || parse.u != NULL)
		parse.maxk = (unsigned int)linek;
	else
		ft_error_dict(error);
	return (parse);
}
