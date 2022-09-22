/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:59:42 by lloison           #+#    #+#             */
/*   Updated: 2022/09/19 13:31:05 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_FILE_VALID_H
# define IS_FILE_VALID_H

int	is_file_valid(char *file_name);
int	is_file_valid2(int fd, char *valid_chars, char *buf, int nb_line);
int	get_next_line(int fd, char *buf);
int	verify_first_line(char *buf, char *valid_char);
int	verify_first_line2(char *buf, char *valid_char, int *i);
int	verify_line(char *buf, char *valid_chars);
#endif
