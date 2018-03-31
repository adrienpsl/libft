#include "../sources/ft_library_header.h"

t_sll_l link_test;

void static init()
{
	link_test = new_sll_l("lala", 4);
}

void static destroy()
{
	destroy_sll_l(&link_test);
	link_test = new_sll_l("lala", 0);
	link_test = new_sll_l(NULL, 10);
}

static void test__1_() // check si destruct et construct work
{
	init();
	destroy();
}

void all_test_sll_l()
{
	test__1_();
}

//int main()
//{
//	all_test_();
//	return (0);
//}
