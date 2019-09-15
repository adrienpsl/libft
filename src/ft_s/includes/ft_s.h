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

#ifndef FT_S_H
#define FT_S_H

# include "stdio.h"

typedef struct s_s
{
	size_t capacity;
	size_t length;
	char *data;
} t_s;

t_s *fts__init(size_t size);
int fts__add(t_s *s, char *str);
int fts__addn(t_s *s, char *str, size_t length);
int fts__add_at(t_s *s, char *str, size_t index);
void fts__free(t_s **s);
void fts__remove_from(t_s *s, size_t start);
int fts__clear(t_s *s);
int fts__search_str(t_s *s, char *wanted);
int fts__replace_str(t_s *s, char *wanted, char *substitute);

#endif
