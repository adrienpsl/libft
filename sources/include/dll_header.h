/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sll_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:43:59 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_HEADER_H
# define DLL_HEADER_H

# include <stdlib.h>
# include "dll_l_header.h"
# include "dll_c_header.h"

/*
**    structure
*/
typedef struct		s_dll_00
{
	size_t			length;
	t_dll_l			top;
	t_dll_l			end;
}					t_dll_00;
typedef t_dll_00	*t_dll;

/*
**    construct ================================================================
*/
void				destroy_dll(t_dll *dll);
void				destroy_dll_func(t_dll *l, void (*func) (t_dll_l));

t_dll				new_dll();

/*
**    method ===================================================================
*/
t_dll_l				dll_add(t_dll_l link, t_dll list);
t_dll_l				dll_push(t_dll_l link, t_dll list);
t_dll_l				dll_index(t_dll_l link, t_dll list, size_t index);

t_dll_l				dll_drop_end(t_dll list);
t_dll_l				dll_drop_top(t_dll list);
t_dll_l				dll_drop_index(t_dll list, size_t index);

t_dll_l				dll_find(t_dll list,
							int(*func)(t_dll_l, void *), void *ptr);

void				dll_fill_list_circular(t_dll_c c_list,
					t_dll list, size_t lenght);

/*
**    utils ====================================================================
*/
t_dll_l				dll_list_empty(t_dll_l link, t_dll list);
t_dll_l				dll_drop_list_one(t_dll list);
t_dll_l				get_good_link(size_t index, t_dll list);

/*
**    debug ====================================================================
*/
void				dll_print_nb(t_dll lst);
void				dll_print_nbrev(t_dll lst);
void				dll_print_str(t_dll lst);
void				dll_print_strrev(t_dll lst);

#endif
