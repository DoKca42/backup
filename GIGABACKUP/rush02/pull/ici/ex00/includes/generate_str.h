/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-vaul <mde-vaul@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:44:30 by mde-vaul          #+#    #+#             */
/*   Updated: 2022/09/18 18:45:58 by mde-vaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATE_STR_H
# define GENERATE_STR_H

int		get_cent(t_dict *data, char *nbr, char *output, int is_last);
int		get_k(t_dict *data, int n, char *output);
int		ft_strcpy(char *src, char *dst);
char	*generate_str(t_dict *data, t_parsed_input *input);
#endif
