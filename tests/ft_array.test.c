#include <ft_array.h>

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
	ft_array_free(&array);
	// print le
}

void test_ft_array()
{
	// test init and destroy
	test_ft_array_init((t_test) {
	.test_nb = 1,
	.nb_element = 10,
	.size_element = sizeof(int),
	.int_arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	});

	// test
}