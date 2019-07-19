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

int ft_put_int(char *str, int ret)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (ret);
}

void *ft_putstr_retptr(char *str, void *ret)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (ret);
}
