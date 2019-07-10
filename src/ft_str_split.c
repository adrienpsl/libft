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

static int count_words(char *s, char separators)
{
	size_t words;

	words = 0;
	while (*s)
	{
		while (*s && ft_char_test(*s, separators))
			s++;
		if (*s && !ft_char_test(*s, separators))
		{
			words++;
			while (*s && !ft_char_test(*s, separators))
				s++;
		}
	}
	return words;
}

static int dup_word(char **s, char **out, char separators)
{
	size_t size;

	size = 0;
	while (**s && ft_char_test(**s, separators))
		(*s)++;
	while ((*s)[size]
		   && *s && !ft_char_test((*s)[size], separators))
		size++;
	if (!(*out = ft_memdup(s, size)))
		return (-1);
	*s += size;
	return (0);
}

char **ft_str_split(char *s, char separators)
{
	int words;
	char **split;
	char *tmp;
	int i;

	i = 0;
	if (s == NULL)
		return (NULL);
	words = count_words(s, separators);
	if (!(split = malloc(sizeof(char *) * (words + 2))))
		return (NULL);
	while (i < words)
	{
		if (dup_word(&s, &tmp, separators))
			return (NULL);
		split[i] = tmp;
		i++;
	}
	split[i] = NULL;
	split[i + 1] = NULL;
	return (split);
}
