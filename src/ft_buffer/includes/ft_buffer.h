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

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

# include "stdio.h"

# define BUFFER_SIZE 1023

typedef struct		s_buffer
{
	int				length;
	char			data[BUFFER_SIZE + 1];
	int				fd;
}					t_buffer;

t_buffer			*ft_buffer_new(size_t size, int fd);
int					ft_buffer_add(t_buffer *buff, char *data, int size);
int					ft_buffer_clean(t_buffer *buff);

#endif
