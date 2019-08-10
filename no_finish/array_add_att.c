//
// Created by adpusel on 2019-08-10.
//


#include <ft_array.h>
#include <libft.h>

static int ft_array_move_end(t_array *array, int start)
{
	int index;

	if (array->length + 1 >= array->capacity)
		return (ft_errno_set(EFAULT, -1));
	index = array->length;
	while (index >= start)
	{
		ft_memcpy(ft_array_at(array, index + 1),
				  ft_array_at(array, index),
				  array->element_size);
		index = index - 1;
	}
	return (0);
}

int ft_array_add_at(t_array **p_array, void *element, int index)
{
	t_array *array;

	if (!p_array || !*p_array || !element)
		return (ft_errno_set(EINVAL, -1));
	array = *p_array;
	if (array->length + 1 >= array->capacity
		&& !(array = ft_array_copy(array)))
		return (-1);
	if (array->length && ft_array_move_end(array, index))
		return (-1);
	ft_memcpy(ft_array_at(array, index), element, array->element_size);
	array->length += 1;
	*p_array = array;
	return (0);
}
