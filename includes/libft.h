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
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>
# include <ctype.h>
# include <stdlib.h>

# include "libft_struct.h"
# include "ft_printf.h"
# include "libft_define.h"

/*
** define
*/
# define FT_CHAR_ASCII 1
# define FT_CHAR_DIGIT 2
# define FT_CHAR_ALPHA 3
# define FT_CHAR_ALPHA_DIGIT 4
# define FT_CHAR_SPACE 5
# define FT_CUSTOM_SEPARATOR 6
# define FRESH NULL

# define BUFF_SIZE 4096

/*
**	global variable
*/
int g_test;
char g_test_buffer[10000];


/*
**	io
*/
int get_next_line(const int fd, char **line, int need_free);
int ft_atoi(const char *str);
int ft_itoa_base(uintmax_t origin_nb, const char *base_str, char *out, int is_u);
int ft_io_catch_options(char *av_string, char *str_option, long *options);
/*
**	test
*/
int ft_test_streq(char const *s1, char const *s2);

/*
**	split
*/
void ft_strsplit_print(char **p_str, char sep);
char **ft_split_mix(char **split_1, char **split_2, int do_free);
void ft_str_split_free(char ***p_str);
void ft_strsplitprint_test(char **p_str);
char **ft_str_split(char *s, char *separators);
int ft_str_split_count(char **split);
int ft_str_split_cmp(char **split_1, char **split_2);
char **ft_str_split_remove(char **split, char *s);
char **ft_str_split_copy(char **split, int free);
char **ft_str_split_add(char **split, char *s, int free);

/*
**	str
*/
char *ft_strsub(char const *s, unsigned int start, size_t len);
size_t ft_strlen(const char *str);
void ft_putstr_buffer(const char *s, char *buffer);
void ft_putendl(char const *s);
void ft_putendl_fd(char const *s, int fd);
void ft_putnstr(char const *str, size_t str_len);
void ft_putnstr_fd(char const *str, size_t str_len, int fd);
void ft_putstr(char const *s);
void ft_putstr_fd(char const *s, int fd);
char *ft_strndup(const char *s, size_t size);
char *ft_strdup(const char *s);
void ft_strchrnreplace(char *str, char *matched, char replacing, size_t size);
void ft_strchrreplace(char *str, char *matched, char replacing);
void ft_print_two_split(char **test, char **res);
ssize_t ft_strchr(char *str, char c);


/*
**	memory
*/
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *restrict str1, const void *restrict str2, size_t n);
void *ft_memalloc(size_t size);
void *ft_memccpy(void *restrict dest,
 const void *restrict src, int c, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void ft_memdel(void **ap, size_t size);
void *ft_memmove(void *d, const void *s, size_t n);
void *ft_memset(void *s, int c, size_t n);
void *ft_memdup(const void *src, size_t size);

/*
**	char
*/
void ft_putchar_fd(char c, int fd);
void ft_putchar(char c);
int ft_char_test(int c, int test_type);
int ft_capitalise(int c, int mode);
int ft_isalpha(int c);
int ft_isalnum(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_isascii(int c);
int ft_isspace(int c);




void *ft_putstr_retptr(char *str, void *ret);
int ft_strsplit_search(char **split, int(*f)(char *, void *), void *param);
int ft_strsplit_search_streq(char *current, void *p_searched);
void ft_test_ifcmp_printsplit(char **res, char **test);
void ft_test_clear_testbuff();
void ft_test_if_streq(char *res, char *test);

char *ft_str_replace(char *str, char *searching, char *replacing);
char *ft_str_replacebuffer(char *out, char *str, char *searching, char *replacing);
int ft_str_search(char *str, char *searching);
ssize_t ft_strchrstr(char *str, char *searched);
t_buffer *ft_buffer_new(size_t size, int fd);
int ft_buffer_add(t_buffer *buff, char *data, size_t size);
int ft_buffer_clean(t_buffer *buff);
int ft_streq(char const *s1, char const *s2);
t_array *ft_array_new(int length, int size_el);
void ft_array_free(t_array **p_array);
void ft_array_clean(t_array *array);

t_array *ft_array_dup_bigger(t_array **p_origin, size_t add_size);
t_array *ft_array_dup(t_array *origin, size_t size);

void *ft_array_el(t_array *array, int i);
void *ft_array_next_el(t_array *array);
int ft_putstr_retint(char *str, int ret);
int ft_strneq(char const *s1, char const *s2, size_t size);
int ft_array_cmp(t_array *array_1,
 t_array *array_2,
 int (*f)(void *, void *),
 int mode);

int ft_strnchr(char *str, char c);
void *ft_array_func(t_array *array, int(*f)(void *, void *, void *), void *param);
int ft_quick_sort(t_sort *quick, int low, int high);
int ft_array_bubble(t_sort *s);
char *ft_strjoinbuffer(char *dest, const char *s1, const char *s2, int do_free);
char *ft_strjoin(const char *s1, const char *s2, int do_free);
char *ft_strjoinby(char *start, char *middle, char *end, int do_free);
char * ft_strjoinbybuffer(char *dest, const char *start, char *middle, char *end);
char *ft_strnew(size_t size);
int ft_str_cmp(const char *s1, const char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t len);
char	*ft_strcat(char *restrict dest, const char *restrict src);
#endif
