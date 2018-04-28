//
// Created by Adrien PUSEL on 12/31/17.
//

#ifndef LIBFT_MEMORY_FUNCTION_H
# define LIBFT_MEMORY_FUNCTION_H

#include <unistd.h>

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset (void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**  mine
*/
void				ft_exit_lack_memory(void);
size_t				soa(void *data, char type);
void				*ft_malloc_protect(size_t size);

#endif
