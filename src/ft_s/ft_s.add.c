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

#include <ft_s.h>
#include <ft_log.h>
#include <ft_str.h>

static int			check(t_s *s, char *string)
{
	if (NULL == s)
	{
		return (ftlog__message(F, L,
				"fts__add error: s ptr (null)",
				EINVAL));
	}
	if (NULL == string)
	{
		return (ftlog__message(F, L,
				"fts__add error: str ptr (null)",
				EINVAL));
	}
	return (0);
}

int					fts__add(t_s *s, char *str)
{
	if (check(s, str))
		return (-1);
	return (fts__addn(s, str, ft_strlen(str)));
}
