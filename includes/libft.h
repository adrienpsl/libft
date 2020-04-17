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

#ifndef LIBFT_H
#define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include "ft_list.struct.h"
# include "stdlib.h"
# include <stdbool.h>

ssize_t ft_strchr_int(char *str, char c);
char *ft_strchr(char *str, char c);
int ft_isdigit(int c);
int ft_atoi(const char *str);
int ft_strlen(const char *str);
int ft_strcmp(char *s1, char *s2);

void *ft_memcpy(void *dest, const void *src, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memalloc(size_t size);

t_list *ft_lstnew(const void *content, size_t content_size);
void ft_lstdel(t_list *p_list, void (*del)(void *, size_t));
void ft_lstaddend(t_list *lst, t_list *new);
void ft_lstadd(t_list **lst, t_list *new);
void ft_lst_reverse(t_list **lst);
t_list *ft_listfunc(t_list *list, bool (*f_test)(t_list *, void *), void *ptr);

uint64_t ft_bswap_64(uint64_t value);
uint32_t ft_bswap_32(uint32_t value);
uint16_t ft_bswap_16(uint16_t value);

void print_section_list(t_list *list);
#endif
