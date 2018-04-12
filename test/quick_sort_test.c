#include "../sources/ft_library_header.h"

static void test__1_() // check si destruct et construct work
{
	int count = 0;

	int tab[16] = { 14, 12, 11, 10, 2, 9, 13, 5, 4, 6, 0, 7, 8, 15, 1, 3 };

	ft_quick_sort(tab, 0, 15, 15);
	debug_print_tab_nb(tab, 16);

	ft_printf("------%d \n", count);
}

void all_test_()
{
	test__1_();
}

int main()
{
	all_test_();
	return (0);
}
