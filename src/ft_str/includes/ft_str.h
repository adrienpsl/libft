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
void ft_putendl(char const *s);
void ft_putendl_fd(char const *s, int fd);
void ft_putnstr(char const *str, size_t str_len);
void ft_putnstr_fd(char const *str, size_t str_len, int fd);
void ft_putstr(char const *s);
void ft_putstr_fd(char const *s, int fd);
void *ft_put_ptr(void *ret, char *str);
int ft_put_int(int ret, char *str);
int ft_putval_int(int ret, char *text, char *value);

/*
**	utils
*/
void ft_str$free(char **s);
size_t ft_strlen(const char *str);

/*
**	test
*/
int ft_streq(char const *s1, char const *s2);
int ft_strneq(char const *s1, char const *s2, size_t size);
int ft_str_cmp(const char *s1, const char *s2);
int ft_test_streq(char const *s1, char const *s2);

/*
**	search
*/
void ft_strchrnreplace(char *str, char *matched, char replacing, size_t size);
void ft_strchrreplace(char *str, char *matched, char replacing);
ssize_t ft_strchr(char *str, char c);
int ft_str_search$start(char *src, char *searching);
char *ft_str_replace(char *str, char *searching, char *replacing, int do_free);
char *
ft_str_replacebuffer(char *out, char *str, char *searching, char *replacing);
int ft_str_search(char *src, char *searching);
ssize_t ft_strchrstr(char *str, char *searched);
int ft_strnchr(char *str, char c);



/*
**	memory
*/
char *ft_strsub(char const *s, unsigned int start, size_t len);
void ft_putstr_buffer(const char *s, char *buffer);
char *ft_strndup(const char *s, size_t size);
char *ft_strdup(const char *s);
char *ft_strnjoin(char *s1, char *s2, size_t size, int do_free);
char *ft_strjoinbuffer(char *dest, const char *s1, const char *s2, int do_free);
char *ft_strjoin(const char *s1, const char *s2, int do_free);
char *ft_strjoinby(char *start, char *middle, char *end, int do_free);
char *
ft_strjoinbybuffer(char *dest, const char *start, char *middle, char *end);
char *ft_strnew(size_t size);
size_t ft_strlcat(char *dst, const char *src, size_t len);
char *ft_strcat(char *restrict dest, const char *restrict src);

/*
**	char
*/
void ft_putchar_fd(char c, int fd);
void ft_putchar(char c);
int ft_capitalise(int c, int mode);
int ft_isalpha(int c);
int ft_isalnum(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_isascii(int c);
int ft_isspace(int c);

#endif
