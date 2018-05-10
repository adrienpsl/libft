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

#ifndef SLL_L_HEADER_H
# define SLL_L_HEADER_H

# include <stdlib.h>

/*
**    structure
*/
typedef struct			s_sll_l_00
{
	void				*content;
	size_t				content_size;
	struct s_sll_l_00	*next;
}						t_sll_l_00;
typedef t_sll_l_00		*t_sll_l;

/*
**    construct ================================================================
*/
void					destroy_sll_l(t_sll_l *sll_l);
t_sll_l					new_sll_l(void *content, size_t size);

/*
**    method ===================================================================
*/

/*
**    utils ====================================================================
*/

/*
**    debug ====================================================================
*/

#endif
