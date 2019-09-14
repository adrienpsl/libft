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
#include "libft.h"

static int check(t_s *s, char *wanted, char *substitute)
{
	if (NULL == s)
		return (
			ftlog__message(F, L,
						   "fts__replace_str error: s ptr (null)",
						   EINVAL)
		);
	if (NULL == wanted || NULL == substitute)
		return (
			ftlog__message(F, L,
						   "fts__replace_str error:"
						   "wanted or length_substitute  ptr (null)",
						   EINVAL)
		);
	return (OK);
}

int fts__replace_str(t_s *s, char *wanted, char *substitute)
{
	ssize_t index;
	t_s *s_tmp;

	if (OK != check(s, wanted, substitute))
		return (-1);
	if (0 > (index = fts__search_str(s, wanted))
		|| NULL == (s_tmp = fts__init(s->length + ft_strlen(substitute)))
		)
		return (-1);
	fts__addn(s_tmp, s->data, index);
	fts__add(s_tmp, substitute);
	fts__add(s_tmp, s->data + index + ft_strlen(wanted));
	free(s->data);
	ft_memcpy(s, s_tmp, sizeof(t_s));
	free(s_tmp);
	return (OK);
}