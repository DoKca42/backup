/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:06:22 by loculy            #+#    #+#             */
/*   Updated: 2022/09/18 15:51:25 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_parsing
{
	unsigned int	key;
	char			*value;
}	t_parsing;

typedef struct s_dict
{
	unsigned int	maxk;
	t_parsing		*k;
	t_parsing		*u;
}	t_dict;

void			ft_error_dict(int *error);
void			ft_error_in(int *error);
void			ft_check_err(unsigned char *tab, int i, int *error, int size);
struct s_dict	ft_check_i(int i, t_dict parse, int linek, int *error);
void			ft_list_size(int size, int *uk);
int				parsing_size(int *error);
unsigned char	*parsing_convert(int *error);
char			*ft_valuemalloc(unsigned char *tab, int i);
int				ft_k_sw(int *d, int *linek, t_parsing *k, unsigned char *tab);
int				ft_u_sw(int *d, int *lineu, t_parsing *u, unsigned char	*tab);
struct s_dict	parsing_list_fill(unsigned char *tab, int k, int u, int *error);
struct s_dict	parsing_read(int *error);

#endif 
