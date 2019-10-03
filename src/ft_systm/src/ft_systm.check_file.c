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

int	ftsystm__check_file(char *path, char *prg_name, char *file_name)
{
	if (!path || !prg_name || !file_name)
		return (-1);
	if (OK != access(path, F_OK))
	{
		ft_printf("%s: no such file or directory: %s\n", prg_name, file_name);
		return (-1);
	}
	if (OK != access(path, R_OK))
	{
		ft_printf("%s: permission denied: %s\n", prg_name, file_name);
		return (-1);
	}
	return (OK);
}
