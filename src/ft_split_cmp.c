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

int ft_str_split_cmp(char **split_1, char **split_2)
{
	if (!split_1 || !split_2)
		return (0);
	while (*split_1)
	{
		if (ft_memcmp(*split_1, *split_2, ft_strlen(*split_1)))
		{
			ft_printf("%s -- %s\n", *split_1, *split_2);
			return (1);
		}
		split_1++;
		split_2++;
	}
	return (0);
}
