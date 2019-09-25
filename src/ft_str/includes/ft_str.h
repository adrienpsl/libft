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

# include "unistd.h"

/*
**	print function
*/
void ft_putstr_fd(char const *s, int fd);
void ftstr__free(char **s);
int ft_strlen(const char *str);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strjoin(char *start, char *end, int free);
int ftstr__search_start(char *current, char *searching);
int ftstr__search_start_strict(char *current, char *searching);
char *ftstr__find_str(char *str, char *wanted);
char *ftstr__replace_str(char *src, char *from, char *to);
ssize_t ftstr__search_str(char *src, char *searching);
ssize_t ft_strchrs(char *str, char *searched);
int ft_strnchr(char *str, char c);
int ft_strncmp(char const *s1, char const *s2, size_t n);
int ft_streq(const char *s1, const char *s2);

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
int ft_pstrjoin_chr(char *start, char c, int need_free, char **out);
int ft_pstrjoin(char *start, char *s_end, int need_free, char **out);

/*
**	char
*/
int ft_isalpha(int c);
int ft_isalnum(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_isascii(int c);
int ft_isspace(int c);

/*
**	Search
*/
ssize_t ft_strchr_int(char *str, char c);
char		*ftstr__strchr(char *str, char c);

#endif
