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
#include "ft_errno.h"

void	ft_perror(char *string)
{
	int errnum;

	errnum = ft_errno_get();
	if (errnum == 0)
		return ;
	if (string == NULL)
		return ;
	ft_putstr_fd(string, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(ft_strerror(errnum), 2);
	ft_putstr_fd("\n", 2);
}
