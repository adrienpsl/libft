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

#ifndef LIBFT_FT_STR_H
#define LIBFT_FT_STR_H

#define FTSTR__SEARCH_START_STRICT 1
#define FTSTR__SEARCH_START_PARTIAL 0

# include "unistd.h"

/*
**	print function
*/
void ft_putendl_fd(char const *s, int fd);
void ft_putstr_fd(char const *s, int fd);

/*
**	utils
*/
void ftstr__free(char **s);
int ft_strlen(const char *str);

/*
**	test
*/
int ft_str_cmp(const char *s1, const char *s2);

/*
**	search
*/
int ftstr__search_start(char *current, char *searching, int param);
int ft_str_search(char *src, char *searching);
ssize_t ft_strchrstr(char *str, char *searched);
int ft_strnchr(char *str, char c);

/*
**	memory
*/
char *ft_strsub(char const *s, int start, size_t len);
void ft_putstr_buffer(const char *s, char *buffer);
char *ft_strndup(const char *s, size_t size);
char *ft_strdup(const char *s);
size_t ft_strlcat(char *dst, const char *src, size_t len);
char *ft_strcat(char *restrict dest, const char *restrict src);
void ftstr__add_buffer(char *buffer, char *s1, char *s2, char *s3);

/*
**	char
*/
int ft_isalpha(int c);
int ft_isalnum(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_isascii(int c);
int ft_isspace(int c);
ssize_t ft_strchr(char *str, char c);

#endif
