#include "libft.h"

int test_ft_buffer()
{
	t_buffer *buff;
	size_t size;

	/* create --------------------------------------------------------------- */
	buff = ft_buffer_new(15, 10);
	/* free ----------------------------------------------------------------- */
	ft_memset(buff, 0, sizeof(t_buffer) + buff->length);
	free(buff);

	/* buffer_add ----------------------------------------------------------- */
	buff = ft_buffer_new(15, 10);

	char *str = "012345678910";
	size = ft_strlen(str);
	ft_buffer_add(buff, str, size);
	if (strcmp(buff->data, str) || buff->i != 12)
		printf("ft_buffer_add_1\n");

	ft_buffer_add(buff, "1112", STRING_MODE);
	if (strcmp(buff->data, "1112") || buff->i != 4)
		printf("ft_buffer_add_2\n");

	/* buffer_clean --------------------------------------------------------- */
	ft_buffer_clean(buff);
	if (strcmp(buff->data, "") || buff->i)
		printf("ft_buffer_clean");

	return 0;
}