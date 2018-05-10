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

#ifndef LIBFT_DLL_C_HEADER_H

# define LIBFT_DLL_C_HEADER_H
# include <stdlib.h>
# include "dll_l_header.h"

/*
**    structure
*/
typedef struct			s_dll_c_00
{
	size_t				length;
	t_dll_l				top;
}						t_dll_c_00;
typedef t_dll_c_00		*t_dll_c;

/*
**    construct ================================================================
*/
void					destroy_dll_c(t_dll_c *dll_c);
t_dll_c					new_dll_c();

/*
**    method ===================================================================
*/
t_dll_l					dll_c_push_link(t_dll_l link, t_dll_c c_list);
t_dll_l					dll_c_drop_link(t_dll_c c_list);
t_dll_l					dll_l_iter_int(t_dll_c c_list, int nb,
						int(*func)(int a, int b));
t_dll_l					dll_c_find_nb(t_dll_c c_list, int nb);
t_dll_l					dll_c_add_after(t_dll_l link, t_dll_c c_list);

void					dll_c_copie(t_dll_c list_1,
									t_dll_c list_2, size_t size);
void					dll_link_copie_reverse(t_dll_l link,
												t_dll_c list_2, size_t size);

/*
**    utils ====================================================================
*/

/*
**    debug ====================================================================
*/
void					dll_c_print_lst(t_dll_c lst);
void					dll_c_print_lst_reverse(t_dll_c lst);
void					dll_c_print_lst_str(t_dll_c lst);
void					dll_c_print_lst_str_reverse(t_dll_c lst);

#endif
