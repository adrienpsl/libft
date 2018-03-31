/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/10/19 10:48:07 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

char	*ft_str_rev(char *s)
{
	int		i;
	int		y;
	char	temp;

	y = ft_strlen(s) - 1;
	i = 0;
	while (i < y)
	{
		temp = s[i];
		s[i] = s[y];
		s[y] = temp;
		i++;
		y--;
	}
	return (s);
}
