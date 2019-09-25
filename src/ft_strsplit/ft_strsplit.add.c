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

#include <unistd.h>
#include <libft_define.h>
#include "ft_str.h"
#include "ft_strsplit.h"

int	ft_strsplit_add(char ***split, char *fresh_str)
{
	int		i;
	char	**new_split;

	if (!split || !*split || !fresh_str)
		return (-1);
	if (!(fresh_str = ft_strdup(fresh_str)))
		return (-1);
	i = ft_strsplit_count(*split);
	(*split)[i] = fresh_str;
	if (NULL == (new_split = ft_strsplit_copy(*split, 0)))
		return (-1);
	ft_strsplit_free(split);
	*split = new_split;
	return (OK);
}
