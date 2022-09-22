/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:31:10 by lloison           #+#    #+#             */
/*   Updated: 2022/09/20 14:53:31 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int	parse_file(char *filename, t_map **map);
int	parsing_to_map(char *filename, t_map **map, int length);
#endif
