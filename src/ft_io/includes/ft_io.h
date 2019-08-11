/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FT_IO_H
#define LIBFT_FT_IO_H

# define BUFF_SIZE 4096

# include "ft_str.h"
# include <stdlib.h>
# include <stdint.h>

int get_next_line(const int fd, char **line, int need_free);
int ft_atoi(const char *str);
int ft_itoa_base(
	uintmax_t origin_nb,
	const char *base_str,
	char *out,
	int is_u
);
int ft_io_catch_options(char *av_string, char *str_option, long *options);

#endif
