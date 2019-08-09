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

#ifndef FT_ARRAY_H
#define FT_ARRAY_H

/*
**	External api
*/
#include "unistd.h"

/*
**	Inter Api
*/
# include "libft_define.h"

/*
**	Structure
*/
typedef struct s_array
{
	int length;
	int i;
	int capacity;
	size_t element_size;
	char *buffer;
	char *data;
} t_array;

/*
**	Prototypes ******************************************************
*/

/*
**	the array size is 2x nb_elements, and will expand like vector.
*/
t_array *ft_array_init(int nb_elements, size_t element_size);
void ft_array_free(t_array **p_array);

void *ft_array_next(t_array *array);
void *ft_array_prev(t_array *array);
void *ft_array_at(t_array *array, int index);

int ft_array_add(t_array **p_array, void *element);
int ft_array_add_at(t_array **array, void *element, int index);
int ft_array_remove(t_array *array, int start);

int ft_array_func(t_array *array, int(*f)(void *, void *), void *param);

int ft_array_bubble(
t_array *array,
int(*cmp_f)(void *, void *, int),
int order
);

int ft_array_copy(t_array *dest, t_array *src);

void ft_array_clear(t_array *array);
void *ft_array_position(t_array *array, int index);

typedef t_array t_buffer;

#endif
