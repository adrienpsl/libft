

/*
 * pay attention, the cmp function res is !!
 * */
static int partition(t_array *quick, int low, int high)
{
	t_array *arr;
	int j;
	int i;
	void *pivot;

	arr = quick->array;
	pivot = ft_array_el(arr, high);
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (!quick->cmp_func(ft_array_el(arr, j), pivot, quick->param))
		{
			i++;
			quick->swap_func(ft_array_el(arr, i), ft_array_el(arr, j));
		}
		j++;
	}
	quick->swap_func(ft_array_el(arr, i + 1), ft_array_el(arr, high));
	return (i + 1);
}

int ft_quick_sort(t_sort *quick, int low, int high)
{
	if (low < high && low >= 0)
	{
		int pi = partition(quick, low, high);
		ft_quick_sort(quick, low, pi - 1);
		ft_quick_sort(quick, pi + 1, high);
	}
	return (0);
}
