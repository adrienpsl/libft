

# include "libft.h"
# include "test.h"

char buffer[5000];


int mul_less_10_by_5(void *curent, void *last, void *param)
{
	int nb;
	t_test_ft *test;

	(void) last;
	test = curent;
	nb = *(int *) param;

	if (test->nb == 10)
		return 1;
	test->nb *= nb;
	return 0;
}

int print(void *current, void *last, void *param)
{
	(void) param;
	(void) last;
	t_test_ft *t;

	t = current;
	printf("%d ", t->nb);
	return 0;
}

int compare(void *p1, void *p2, void *param)
{
	t_test_ft *t1;
	t_test_ft *t2;
	int *pa;

	pa = param;
	t1 = p1;
	t2 = p2;
	return pa[0] ? t1->nb < t2->nb : t1->nb > t2->nb;
}

int same(void *p1, void *p2, void *param)
{
	(void) param;
	return p1 == p2;
}

int same_array(t_array *arr_1, t_array *arr_2)
{
	t_test_ft *l1;
	t_test_ft *l2;

	if (arr_1->length != arr_2->length)
		return (1);

	while (arr_1->i < arr_1->length)
	{
		l1 = ft_array_next_el(arr_1);
		l2 = ft_array_next_el(arr_2);
		if (memcmp(l1, l2, sizeof(arr_1->element_size)))
			return (1);
	}
	return (0);
}

int is_sorted(void *p1, void *p2, void *param)
{
	t_test_ft *t1;
	t_test_ft *t2;
	int *pa;

	pa = param;
	t1 = p1;
	t2 = p2;
	if (t2 == NULL)
		return 0;
	return pa[1] ? t1->nb < t2->nb : t1->nb > t2->nb;
}

void init_array(t_array **arr_ptr, int size)
{
	t_test_ft *current;
	t_array *array;

	array = ft_array_new(20, sizeof(t_test_ft));

	*arr_ptr = array;

	for (int i = 0; i < size; ++i)
	{
		current = ft_array_el(array, i);
		current->nb = i;
	}
}

int cmp_tab(t_array *array, int *res, int size)
{
	t_test_ft *tpm;

	for (int i = 0; i < size; ++i)
	{
		tpm = ft_array_el(array, i);
		if (tpm->nb != res[i])
			return 1;
	}
	return (0);
}

int ft_test_array_func(int SIZE, t_array **arr_ptr)
{
	t_array *arr;

	int res[20] = {
			0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 10, 11, 12, 13, 14,
			15, 16, 17, 18, 19};
	int mul = 5;
	t_test_ft *t_return;

	init_array(&arr, SIZE);

	t_return = ft_array_func(arr, mul_less_10_by_5, &mul);

	if (arr->length > 1 && t_return)
		if (cmp_tab(arr, res, SIZE) || t_return->nb != 10)
			ft_putendl("error : array func test 1 ");

	*arr_ptr = arr;
	return 0;
}

void swap(void *a, void *b)
{
	t_test_ft tmp;

	ft_memcpy(&tmp, a, sizeof(t_test_ft));
	ft_memcpy(a, b, sizeof(t_test_ft));
	ft_memcpy(b, &tmp, sizeof(t_test_ft));

	//	tmp = *(t_test*)a
	//	*(t_test*)a = *(t_test*)b;
	//	*(t_test*)b = tmp;
}

int ft_test_quick_sort(int SIZE)
{
	t_array *arr;


	int croissan[20] = {45, 40, 35, 30, 25, 20, 19, 18, 17, 16, 15, 15, 14,
						13, 12, 11, 10, 10, 5, 0};
//

	init_array(&arr, SIZE);
	ft_test_array_func(SIZE, &arr);

	t_sort quick;
	int option[5] = {1, 0};
	int bad_option[5] = {1, 1};
	quick.array = arr;
	quick.param = option;
	quick.cmp_func = compare;
	quick.swap_func = swap;

	ft_quick_sort(&quick, 0, SIZE - 1);
	if (cmp_tab(arr, croissan, SIZE)
		|| ft_array_func(arr, is_sorted, option)
		|| !(ft_array_func(arr, is_sorted, bad_option)))
		ft_putendl("error quick sort 1");

	int decroissant[20] = {0, 5, 10, 10, 11, 12, 13, 14, 15, 15, 16, 17, 18, 19,
						   20, 25, 30, 35, 40, 45};
	init_array(&arr, SIZE);
	ft_test_array_func(SIZE, &arr);
	option[0] = option[1] = 0;
	bad_option[0] = bad_option[1] = 1;

	quick.array = arr;
	ft_quick_sort(&quick, 0, SIZE - 1);
//	ft_array_func(arr, print, NULL);

	if (cmp_tab(arr, decroissant, SIZE)
		|| !ft_array_func(arr, is_sorted, option)
		|| ft_array_func(arr, is_sorted, bad_option)
			)
		 ft_putendl("error quick sort 1");

	ft_array_free(&arr);
	return (0);
}

int ft_test_handle_array()
{
	static const int SIZE = 20;
	t_array *arr;
	int res[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

	// test creation and deletion of my array
	arr = ft_array_new(SIZE, sizeof(t_test_ft));

	/* ft_array_new --------------------------------------------------------- */
	if (arr->element_size != sizeof(t_test_ft)
		|| arr->length != SIZE
		|| arr->i != 0
		|| arr->data != (void *) arr->data
		|| !arr)
		ft_putendl("error ft_array_new");

	/* ft_array_free -------------------------------------------------------- */
	ft_array_free(&arr);
	if (arr)
		 ft_putendl("error array free");


	/* ft_array_clean ------------------------------------------------------- */
	void *clean;
	init_array(&arr, SIZE);
	clean = ft_memalloc(arr->length * arr->element_size);
	ft_array_clean(arr);
	if (memcmp(arr->data, clean, arr->length * arr->element_size))
		ft_putendl("error ft_clean_array");
	ft_array_free(&arr);

	/* ft_array_dup --------------------------------------------------------- */
	t_array *dup;
	init_array(&arr, SIZE);
	dup  = ft_array_dup(arr, SAME_SIZE);
	if (!dup || same_array(arr, dup))
		 ft_putendl("error ft_array_dup");
	ft_array_free(&arr);
	ft_array_free(&dup);


	/* ft_array_dup_bigger -------------------------------------------------- */
	int res_bigger[22] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
						  13, 14, 15, 16, 17, 18, 19, 42, -42};
	t_array *bigger;
	t_test_ft *current;
	init_array(&arr, SIZE);
	bigger = ft_array_dup_bigger(&arr, 2);

	bigger->i = bigger->length - 2;
	current = ft_array_next_el(bigger);
	current->nb = 42;
	current = ft_array_next_el(bigger);
	current->nb = -42;
	current = ft_array_next_el(bigger);

	if (!bigger
		|| bigger->length != 22
		|| bigger->i != 0
		|| current != NULL
		|| cmp_tab(bigger, res_bigger, 22))
		 ft_putendl("error ft_array_bigger");;



	/* ft_array_el ---------------------------------------------------------- */
	init_array(&arr, SIZE);
	if (cmp_tab(arr, res, arr->length))
		 ft_putendl("error ft_array_el");


	/* ft_array_next_el ----------------------------------------------------- */
	t_test_ft *tpm;

	size_t i = 0;
	int ret;
	// TODO : why not work ?
	while (i < SIZE)
	{
		tpm = ft_array_next_el(arr);
		if (tpm->nb != res[i] || arr->i != i + 1)
			ret = 1;
		++i;
	}
//	if (ret)
//		 ft_putendl("error ft_array_next_el");

	return (0);
}

void ft_test_bubble_sort()
{
	t_array *array;
	t_sort bubble;
	int option[5] = {0, 0};

	int SIZE = 20;
	int croissant[20] = {0, 5, 10, 10, 11, 12, 13, 14, 15, 15, 16, 17, 18, 19,
						 20, 25, 30, 35, 40, 45};

	// fill to 0..19
	init_array(&array, SIZE);

	// create unsorted array
	ft_test_array_func(SIZE, &array);

	// set up the sorting
	bubble.array = array;
	bubble.param = option;
	bubble.cmp_func = compare;
	bubble.swap_func = swap;

	ft_array_bubble(&bubble);

	if (cmp_tab(array, croissant, SIZE))
		ft_putendl("error : test bubble sort");
}

void test_ft_array_cmp()
{
	t_array *arr_1;
	t_array *arr_2;

	// test with int
	arr_1 = ft_array_new(10, sizeof(int));
	arr_2 = ft_array_new(10, sizeof(int));

	int i = 0;
	while (i < 10)
	{
		*(int *) ft_array_el(arr_1, i) = i;
		*(int *) ft_array_el(arr_2, i) = i;
		i++;
	}

	if (ft_array_cmp(arr_1, arr_2, NULL, FT_CMP_INT))
		ft_putendl("ft_array_cmp 1");

	*(int *) ft_array_el(arr_1, 2) = 9;
	if (!ft_array_cmp(arr_1, arr_2, NULL, FT_CMP_INT))
		ft_putendl("ft_array_cmp 2");

	free(arr_1);
	free(arr_2);

	char *test[20] = {"mager", "chips", "chocolat"};
	char *tmp;

	arr_1 = ft_array_new(3, sizeof(char **));
	arr_2 = ft_array_new(3, sizeof(char **));

	for (int j = 0; j < 2; ++j)
	{
		tmp = ft_array_el(arr_1, j);
		ft_memcpy(tmp, test[j], sizeof(char *));
		tmp = ft_array_el(arr_2, j);
		ft_memcpy(tmp, test[j], sizeof(char *));
	}

	if (ft_array_cmp(arr_1, arr_2, NULL, FT_CMP_INT))
		ft_putendl("ft_array_cmp 1");

	tmp = ft_array_el(arr_1, 1);
	ft_memcpy(tmp, test[0], sizeof(char *));

	if (!ft_array_cmp(arr_1, arr_2, NULL, FT_CMP_INT))
		ft_putendl("ft_array_cmp 2");
}


int test_ft_array()
{

	// pour bien tester, je veux rediriger dans un file a chaque fois ce que je fais, et ensuite, je
	// comparer cette output avec ce que je voulais, comme ca pas besoin de faire des
	// buffer tout ca tout ca !


	test_ft_array_cmp();

	static const int SIZE = 20;
	t_array *arr;

	ft_test_handle_array();
	ft_test_array_func(SIZE, &arr);

	ft_test_quick_sort(SIZE);
	ft_test_bubble_sort();

	return (0);
}
