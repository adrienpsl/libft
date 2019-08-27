
#include <unistd.h>
#include "ft_mem.h"
#include "ft_str.h"

size_t		ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char*)ft_memchr(dst, '\0', len);
	if (!s1)
		return (len + ft_strlen((char*)src));
	s2 = (char*)src;
	i = ft_strlen((char*)dst) + ft_strlen((char*)src);
	while ((size_t)(s1 - dst) < len - 1 && *s2)
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (i);
}
