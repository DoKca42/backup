/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:42:23 by lloison           #+#    #+#             */
/*   Updated: 2022/09/19 17:45:00 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_SQUARE_H
# define FIND_SQUARE_H

int	ft_init(t_map **cmap);
int	ft_check(int y, int x, t_map **cmap);
int	check_mini(int a, int b, int c);
int	ft_result(t_position *pos, t_map **cmap);
#endif
