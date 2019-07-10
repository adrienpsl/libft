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

#ifndef FT_LIBFT_STRUCT
# define FT_LIBFT_STRUCT

#include <stdio.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef union u_ptr {
	void *s;
	char *c_1;
	char **c_2;
	void *v_1;
	void **v_2;
}		t_ptr;

typedef struct		s_array
{
	size_t length;
	size_t size_el;
	size_t i;
	size_t param;
	char  *data;
	t_ptr p;

}					t_array;

typedef t_array t_buffer;


typedef struct		s_sort
{
	int(*cmp_func)(void*, void*, void*);
	void(*swap_func)(void *, void *);
	t_array		*array;
	void		*param;
	int sorted;
}					t_sort;

#endif
