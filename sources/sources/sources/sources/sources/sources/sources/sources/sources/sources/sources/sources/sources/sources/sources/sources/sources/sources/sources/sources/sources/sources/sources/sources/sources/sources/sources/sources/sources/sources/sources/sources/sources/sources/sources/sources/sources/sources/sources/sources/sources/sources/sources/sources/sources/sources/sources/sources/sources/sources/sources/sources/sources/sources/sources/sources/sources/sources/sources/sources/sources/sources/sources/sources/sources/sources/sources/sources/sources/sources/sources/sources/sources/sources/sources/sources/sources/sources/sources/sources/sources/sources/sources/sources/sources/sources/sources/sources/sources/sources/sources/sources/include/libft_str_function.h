//
// Created by Adrien PUSEL on 12/31/17.
//

#ifndef LIBFT_STR_FUNCTION_H
# define LIBFT_STR_FUNCTION_H

# include <unistd.h>

/*
**  char function
*/
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
**  str function
*/
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_charcat(char *dest, const char src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strndup(char const *s, size_t len);
size_t				ft_strchr_how_many(char const *str, char c);
char				get_last_char_str(char *s);
char				*ft_strnjoin(char const *s1, char const *s2, size_t n);
int					str_by_func(char *s, int (*f)(int));
size_t				ft_strchr_len(char *s, char c);
int					check_char_into_str(char *str, char c);
char				*ft_strchr_dup(char *s, char c);
long long			index_of_char(char *s, char c);
char				*ft_str_rev(char *str);
int					ft_is_all_number(char *s);


char				**ft_strsplit(char const *s, char c);
void				ft_free_split(char ***t);
void				ft_free_doublechar_tab(char ***tab);

/*
**  uni function
*/
void				ft_put_uni(int c);

#endif
