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

# include "libft.h"

t_array *ft_array_init(int nb_elements, size_t element_size)
{
	t_array *array;

	nb_elements = nb_elements * 2;
	array = ft_memalloc(nb_elements * element_size);
	if (array)
	{
		array->capacity = nb_elements;
		array->data = (char *) array + sizeof(t_array);
		array->element_size = element_size;
		return (array);
	}
	else
	{
		ft_errno_set(ENOMEM, -1);
		return(NULL);
	}
}