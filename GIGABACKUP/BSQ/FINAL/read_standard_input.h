/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_standard_input.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:25:20 by lloison           #+#    #+#             */
/*   Updated: 2022/09/20 19:56:43 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_STANDARD_INPUT_H
# define READ_STANDARD_INPUT_H

typedef struct s_data
{
	int		size;
	char	buf[4096];
	char	c;
	int		i;
	char	valid_chars[2];
	int		first_line_done;
	int		is_error;
	int		nb_lign;
	int		length;
}	t_data;

void	read_standard_input(void);
void	read_standard_input2(t_data **data, t_map **map);
void	read_buf(t_data **data, t_map **map);
void	initialize_data(t_data **data);
void	clear_buffer(char *buf);
int		r_verify_first_line(char *buf, char *valid_chars);
#endif
