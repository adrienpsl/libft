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

#ifndef SLL_HEADER_H
# define SLL_HEADER_H

# include <stdlib.h>
# include "sll_l_header.h"

/*
**    structure
*/
typedef struct		s_sll_00
{
	size_t			lenght;
	t_sll_l			top;
	t_sll_l			tail;
}					t_sll_00;

typedef t_sll_00	*t_sll;
typedef t_sll		t_sll000000000000;

/*
**    construct ================================================================
*/
void				destroy_sll(t_sll *l);
t_sll				new_sll(void);

/*
**    method ===================================================================
*/
t_sll_l				sll_add(t_sll_l link, t_sll list);
t_sll_l				sll_drop_link(t_sll_l link, t_sll list);
t_sll_l				sll_drop_index(t_sll_l link, t_sll list);

/*
**    utils ====================================================================
*/

/*
**    debug ====================================================================
*/
void				sll_print_str(t_sll list);
void				sll_print_str_link(t_sll_l link);

#endif
