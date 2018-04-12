#include "../sources/ft_library_header.h"

static void test__1_() // check si destruct et construct work
{
	int count = 0;

	int tab[71] = { 56,9,16,36,46,25,24,43,23,22,54,62,64,49,35,28,2,30,5,58,18,14,1,33,19,48,67,42,32,8,3,26,17,7,52,45,69,55,15,10,44,6,34,40,51,38,47,60,0,41,37,70,66,65,4,61,50,53,57,31,68,12,21,20,13,63,29,39,11,59,27

	};

	ft_quick_sort(tab, 0, 70);
	debug_print_tab_nb(tab, 71);

	ft_printf("------%d \n", count);
}

static void test__2_() // test avec les dll
{
	int i = 0;

	t_dll list = new_dll();
	t_dll_l link;
	int tab[71] = { 56,9,16,36,46,25,24,43,23,22,54,62,64,49,35,28,2,30,5,58,18,14,1,33,19,48,67,42,32,8,3,26,17,7,52,45,69,55,15,10,44,6,34,40,51,38,47,60,0,41,37,70,66,65,4,61,50,53,57,31,68,12,21,20,13,63,29,39,11,59,27
	 };


	 while (i < 71)
	{
	    link = new_dll_l(tab + i, sizeof(int));
	    dll_add(link, list);
	    i++;
	}
	ft_quick_sort_dll(list->top, list->end, list);
	dll_print_nb(list);

}

void all_test_()
{
	test__1_();
	test__2_();
}

int main()
{
	all_test_();
	return (0);
}
