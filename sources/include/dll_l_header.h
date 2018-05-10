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

#ifndef DLL_L_HEADER_H
# define DLL_L_HEADER_H
# include <stdlib.h>

/*
**    structure :
*/
typedef struct			s_dll_l_00
{
	void				*content;
	size_t				content_size;
	struct s_dll_l_00	*next;
	struct s_dll_l_00	*prev;
}						t_dll_l_00;
typedef t_dll_l_00 *t_dll_l;

/*
**    construct
*/
void					destroy_dll_l(t_dll_l *l);
t_dll_l					new_dll_l(void *content, size_t size);
void					destroy_dll_l_func(t_dll_l *l, void (*func) (t_dll_l));

/*
**    utils =======================
*/
void					reset_ptr_dll_l(t_dll_l link);

/*
**    getter data
*/
int						dll_l_get_int(t_dll_l link);

#endif
