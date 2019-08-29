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
	size_t i;
	char *data;
} t_s;

t_s *fts__init(size_t size);
int fts__add(t_s *s, char *str);
void fts__free(t_s **s);
int fts__clear(t_s *s);

#endif
