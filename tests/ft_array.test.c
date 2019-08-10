#include <ft_array.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct s_test_ft_array
{
	int test_nb;
	int nb_element;
	int size_element;
	int int_arr[30];
	t_array array_resultat;
} t_test;

void test_ft_array_init(t_test test)
{
	t_array *array;

	array = ft_array_init(test.nb_element, test.size_element);

	if (array->capacity != (test.nb_element * 2) - 3 ||
		array->element_size != sizeof(int))
	{
		printf("error test : %d \n", test.test_nb);
	}
	ft_array_free(&array);
	if (array)
		printf("error test : %d at free \n", test.test_nb);
}

int my_rand(int limit)
{
	return rand() % limit + 1;
}

void test_ft_array()
{
	//	// test init and destroy
	//	test_ft_array_init((t_test) {
	//	.test_nb = 1,
	//	.nb_element = 10,
	//	.size_element = sizeof(int),
	//	.int_arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	//	});

	/* test add  ------------------------------------------------------------ */
	// add one element
	t_array *test_add_array = ft_array_init(10, sizeof(int));

	for (int i = 0; i < 2000; ++i)
	{
		ft_array_add(&test_add_array, &i);
	}
	//	ft_array_func(test_add_array, ft_array_func_print$int, NULL);
	ft_array_free(&test_add_array);
	printf(" \n");

	// test array add string
	t_array *test_add_string = ft_array_init(1, sizeof(char *));
	for (int i = 0; i < 2000; ++i)
	{
		char *a = "tata";
		ft_array_add(&test_add_string, a);
	}
	//	ft_array_func(test_add_string, ft_array_func_print$str, NULL);
	ft_array_free(&test_add_string);

	// test with add at the middle bottom ...
	t_array *test_add_random = ft_array_init(2000, sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < 10000; ++i)
	{
		ft_array_add_at(&test_add_random, &i, my_rand(2000));
	}
	//	ft_array_func(test_add_random, ft_array_func_print$int, NULL);
	//	printf("\n%d \n", test_add_random->length);
	ft_array_free(&test_add_random);


	/* test delete ---------------------------------------------------------- */
	t_array *test_delet_all = ft_array_init(1, sizeof(char *));
	for (int i = 0; i < 2000; ++i)
	{
		char *a = "tata";
		ft_array_add(&test_delet_all, a);
	}



	// test delete


	// test le cmp pour pouvoir tester les autres
	// cmp string
	// int
	// with function
















}