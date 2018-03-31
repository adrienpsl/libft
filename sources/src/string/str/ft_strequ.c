/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:08 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (!s1[i] && !s2[i])
		return (1);
	while (s1[i] == s2[i] && s1[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}
