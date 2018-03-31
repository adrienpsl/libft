/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:48 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

static char			**double_malloc(int mal2)
{
	char **tab;

	if (!(tab = (char**)malloc(sizeof(char*) * (mal2))))
		return (NULL);
	tab[mal2 - 1] = 0;
	return (tab);
}

static char			**ft_split(char const *str, int mal2, char c, int i)
{
	char **tab;

	while (*str == c && *str)
		str++;
	while (str[i] != c && str[i] && *str)
		i++;
	if (!(*str))
	{
		if((tab = double_malloc(mal2 + 1)) == FAIL)
			return (FAIL);
		return (tab);
	}
	tab = ft_split(str + i, mal2 + 1, c, 0);
	if (!(tab[mal2] = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		tab[mal2][i] = str[i];
		i++;
	}
	tab[mal2][i] = 0;
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	if (!s || !c)
		return (NULL);
	return (ft_split(s, 0, c, 0));
}
