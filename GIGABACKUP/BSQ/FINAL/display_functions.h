/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:46:37 by lloison           #+#    #+#             */
/*   Updated: 2022/09/20 14:49:37 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_FUNCTIONS_H
# define DISPLAY_FUNCTIONS_H

void	display_map(t_map **map);
void	ft_return_line(int i, int argc);
void	ft_print_res(t_position pos, t_map **map, int size);
int		ft_foreach_files(char **argv, t_position pos, int size, int argc);
#endif
