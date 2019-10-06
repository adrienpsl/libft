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

#ifndef FT_ARRAY_STRUCTURE_H
# define FT_ARRAY_STRUCTURE_H

# include "stdio.h"

typedef struct	s_array
{
	int			length;
	int			i;
	int			capacity;
	size_t		element_size;
	char		*buffer;
	char		*data;
}				t_array;

#endif
