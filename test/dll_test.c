#include "../sources/ft_library_header.h"

t_dll test_dll;

void static init()
{
	test_dll = new_dll();
}

void static destroy()
{
	destroy_dll(&test_dll);
}

static void test__1_() // check si destruct et construct work
{
	init();
	destroy();
}

static void test__2_() // add 1, 2 , 3 maillon et free
{
	init();
	char *str = "test 2 \n add 1, 2 , 3 maillon et free";
	(void) str;

	// init the values
	t_dll dll;
	t_dll_l link_1;
	t_dll_l link_2;
	t_dll_l link_3;

	/*
	**    test avec add ========================================================
	*/
	// set the values
	dll = new_dll();
	link_1 = new_dll_l("1", 2);
	link_2 = new_dll_l("22", 3);
	link_3 = new_dll_l("333", 4);

	// test add
	dll_add(link_1, dll);
	dll_add(link_2, dll);
	dll_add(link_3, dll);
	dll_print_str(dll);
	destroy_dll(&dll);

	/*
	**    test avec push ========================================================
	*/
	// set the values
	dll = new_dll();
	link_1 = new_dll_l("1", 2);
	link_2 = new_dll_l("22", 3);
	link_3 = new_dll_l("333", 4);

	dll_push(link_1, dll);
	dll_push(link_2, dll);
	dll_push(link_3, dll);
	dll_print_strrev(dll);

	destroy_dll(&dll);

	destroy();
}

static void test__3_() // test push et drop 3 maillon
{
	init();
	char *str = "test 3 \n test push et drop 3 maillom";
	(void) str;

	// init the values
	t_dll dll;
	t_dll_l link_1;
	t_dll_l link_2;
	t_dll_l link_3;

	/*
	**    test avec add ========================================================
	*/
	// set the values
	dll = new_dll();
	link_1 = new_dll_l("1", 2);
	link_2 = new_dll_l("22", 3);
	link_3 = new_dll_l("333", 4);


	/*
	**    drop top ========================================================
	*/
	// add les maillon
	dll_add(link_1, dll);
	dll_add(link_2, dll);
	dll_add(link_3, dll);

	// drop tout
	link_1 = dll_drop_top(dll);
	link_2 = dll_drop_top(dll);
	link_3 = dll_drop_top(dll);
	dll_print_str(dll);


	/*
	**    drop end ========================================================
	*/
	// add les maillon
	dll_add(link_1, dll);
	dll_add(link_2, dll);
	dll_add(link_3, dll);

	//	drop tout
	link_1 = dll_drop_end(dll);
	link_2 = dll_drop_end(dll);
	link_3 = dll_drop_end(dll);
	dll_print_str(dll);


	// destroye tt
	dll_add(link_1, dll);
	dll_add(link_2, dll);
	dll_add(link_3, dll);
	destroy_dll(&dll);

	destroy();
}

static void test__4_() // test de index
{
	init();
	char *str = "test 4 \n test de index";
	(void) str;

	// init the values
	t_dll dll;
	t_dll_l link_1;
	t_dll_l link_2;
	t_dll_l link_3;
	t_dll_l link_4;
	t_dll_l link_5;

	dll = new_dll();
	link_1 = new_dll_l("1", 2);
	link_2 = new_dll_l("22", 3);
	link_3 = new_dll_l("333", 4);
	link_4 = new_dll_l("4444", 5);
	link_5 = new_dll_l("55555", 6);

	/*
	**    push ========================================================
	*/
	dll_index(link_1, dll, 0);
	dll_print_str(dll);

	dll_index(link_3, dll, 5);
	dll_print_str(dll);

	dll_index(link_2, dll, 1);
	dll_print_str(dll);

	dll_index(link_4, dll, 3);
	dll_print_str(dll);

	dll_index(link_5, dll, 4);
	dll_print_str(dll);

	/*
	**    drop  ========================================================
	*/
	link_1 = dll_drop_index(dll, 1);
	dll_print_str(dll);

	link_2 = dll_drop_index(dll, 2);
	dll_print_str(dll);

	link_3 = dll_drop_index(dll, 1);
	dll_print_str(dll);

	link_4 = dll_drop_index(dll, 0);
	dll_print_str(dll);

	link_5 = dll_drop_index(dll, 1000);
	dll_print_str(dll);


	dll_add(link_1, dll);
	dll_add(link_2, dll);
	dll_add(link_3, dll);
	dll_add(link_4, dll);
	dll_add(link_5, dll);
	destroy_dll(&dll);
	destroy();
}

void all_test_dll()
{
	test__1_();
	test__2_();
	test__3_();
	test__4_();
}

//int main()
//{
//	all_test_dll();
//	return (0);
//}
