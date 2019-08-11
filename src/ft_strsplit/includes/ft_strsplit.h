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


#ifndef LIBFT_FT_STRSPLIT_H
#define LIBFT_FT_STRSPLIT_H

void ft_strsplit_print(char **p_str, char sep);
void ft_strsplit_remove(char **split, int i);
void ft_strsplit_free(char ***p_str);
char **ft_strsplit(char *s, char *separators);
int ft_strsplit_count(char **split);
int ft_strsplit_cmp(char **split_1, char **split_2);
char **ft_strsplit_copy(char **split, int free);
char **ft_strsplit_add(char **split, char *s, int free);
int ft_strsplit_search(char **split, int(*f)(char *, void *), void *param);
int ft_func_split_streq(char *current, void *p_searched);
void ft_test_ifcmp_printsplit(char **res, char **test, char *where);


char **ft_strsplit_mix(char **split_1, char **split_2, int do_free);
void ft_strsplit_print_test(char **p_str);


#endif
