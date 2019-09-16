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

#include <ft_str.h>

void	ftstr__add_buffer(char *buffer, char *s1, char *s2, char *s3)
{
	if (s1)
		ft_strcat(buffer, s1);
	if (s2)
		ft_strcat(buffer, s2);
	if (s3)
		ft_strcat(buffer, s3);
}

