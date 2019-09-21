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



#ifndef FT_MEM_H
#define FT_MEM_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

#include "ft_array.h"

void	ft_mem_swap(void *p1, void *p2, void *buffer, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *restrict str1, const void *restrict str2, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *restrict dest,
	const void *restrict src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(void *s1, const void *s2, size_t n);
void	ft_memdel(void **ap, size_t size);
void	*ft_memmove(void *d, const void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memdup(const void *src, size_t size);

#endif
