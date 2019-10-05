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

#include <sys/stat.h>
#include <libft.h>

int	ftsystm_check_exe(char *path, char *prg_name, char *file_name)
{
	struct	stat sb;
	int		res;

	res = stat(path, &sb) == 0 && sb.st_mode & S_IXUSR;
	if (res == 0)
		ft_printf("%s: no X right: %s\n", prg_name, file_name);
	return (res ? OK : -1);
}
