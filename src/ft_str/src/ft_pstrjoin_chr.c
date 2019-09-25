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

#include <libft.h>

int	ft_pstrjoin(char *start, char *s_end, int need_free, char **out)
{
	char *new;

	if (NULL == start || NULL == s_end || out == NULL)
		return (-1);
	new = ft_strjoin(start, s_end, need_free);
	if (new)
	{
		*out = new;
		return (OK);
	}
	else
		return (-1);
}

int	ft_pstrjoin_chr(char *start, char c, int need_free, char **out)
{
	char	*new;
	int		length;

	if (NULL == start || NULL == out)
		return (-1);
	length = ft_strlen(start);
	if (NULL == (new = ft_memalloc(length + 2)))
		return (-1);
	ft_strcat(new, start);
	new[length] = c;
	if (need_free)
		ftstr__free(&start);
	*out = new;
	return (OK);
}
