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
t_array *ft_array$init(int nb_elements, size_t element_size);
t_array *ft_array$init_data(void *start, int nb_element, size_t element_size);
t_array *ft_array$slice(t_array *array, int from, int at);
void ft_array$free(t_array **p_array);

void *ft_array$next(t_array *array);
void *ft_array$next_loop(t_array *array);

void *ft_array$prev(t_array *array);
void *ft_array$prev_loop(t_array *array);

void *ft_array$at(t_array *array, int index);

int ft_array$push(t_array **p_array, void *element);
int ft_array$insert(t_array **p_array, void *element, int index);
int ft_array$remove(t_array *array, int index);

void *ft_array$func(t_array *array, int(*func)(void *, void *), void *param);
int ft_array$func_print_str(void *p1, void *param);
int ft_array$func_print_int(void *p1, void *param);

/*
**	--- sort function ----------------------------------------------------------
*/
int ft_array$sort_bubble(
t_array *array, int(*cmp_f)(void *, void *, void *), void *param
);

int ft_array$sort_cmp_int(void *p1, void *p2, void *param);



/*
**	--- cmp function -----------------------------------------------------------
*/
int ft_array$cmp(t_array *array_1, t_array *array_2, int (*f)(void *, void *));
int ft_array$cmp_int(void *p1, void *p2);
int ft_array$cmp_str(void *p1, void *p2);


t_array *ft_array$double_size(t_array *src);
t_array *ft_array$copy(t_array *src);

void ft_array$clear(t_array *array);
void *ft_array$at(t_array *array, int index);


#endif
