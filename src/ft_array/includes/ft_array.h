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
t_array *ftarray__init(int nb_elements, size_t element_size);
t_array *ftarray__init_data(void *start, int nb_element, size_t element_size);
t_array *ftarray__slice(t_array *array, int from, int at);
t_array *ftarray__slice_and_remove(t_array *array, int from, int at);
void ftarray__free(t_array **p_array);

void *ftarray__next(t_array *array);
void *ftarray__next_loop(t_array *array);

void *ftarray__prev(t_array *array);
void *ftarray__prev_loop(t_array *array);

void *ftarray__at(t_array *array, int index);

int ftarray__push(t_array **p_array, void *element);
int ftarray__insert(t_array **p_array, void *element, int index);
int ftarray__remove(t_array *array, int index);
void ftarray__remove_from(t_array *array, int from, int at);

void *ftarray__func(t_array *array, int(*func)(void *, void *), void *param);
int ftarray__func_print_str(void *p1, void *param);
int ftarray__func_print_int(void *p1, void *param);

/*
**	--- sort function ----------------------------------------------------------
*/
int ftarray__sort_bubble(
t_array *array, int(*cmp_f)(void *, void *, void *), void *param
);

int ftarray__sort_cmp_int(void *p1, void *p2, void *param);



/*
**	--- cmp function -----------------------------------------------------------
*/
int ftarray__cmp(t_array *array_1, t_array *array_2, int (*f)(void *, void *));
int ftarray__cmp_int(void *p1, void *p2);
int ftarray__cmp_str(void *p1, void *p2);


t_array *ftarray__double_size(t_array *src);
t_array *ftarray__copy(t_array *src);

void ftarray__clear(t_array *array);


#endif
