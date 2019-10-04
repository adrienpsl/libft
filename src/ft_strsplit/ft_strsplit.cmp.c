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

int					ft_strsplit_cmp(char **split_1, char **split_2)
{
	if (!split_1 && !split_2)
		return (0);
	if (!split_1 || !split_2)
		return (-1);
	while (*split_1 && *split_2)
	{
		if (ft_strcmp(*split_1, *split_2))
			return (1);
		split_1++;
		split_2++;
	}
	if (*split_1 != *split_2)
	{
		ft_printf("split cmp not same end\n");
		return (1);
	}
	return (0);
}
