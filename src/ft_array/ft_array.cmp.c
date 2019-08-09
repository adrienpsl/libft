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

#include "libft.h"

//int ft_array_cmp(t_array *array_1,
//t_array *array_2,
//int (*f)(void *, void *),
//int mode)
//{
//	void *el_1;
//	void *el_2;
//
//	if (!array_1 || !array_2)
//		return (1);
//	array_1->i = 0;
//	array_2->i = 0;
//	while ((el_1 = ft_array_next_el(array_1))
//		   && (el_2 = ft_array_next_el(array_2)))
//	{
//		if (mode == FT_CMP_STRING
//			&& !ft_streq(el_1, el_2))
//			return (1);
//		else if (mode == FT_CMP_INT
//				 && *(int *) el_1 != *(int *) el_2)
//			return (1);
//		else if (f && f(el_1, el_2))
//			return (1);
//	}
//	el_2 = ft_array_next_el(array_2);
//	if (el_1 != el_2)
//		return (1);
//	return (0);
//}
