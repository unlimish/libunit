#include "../../framework/inc/libunit.h"
#include "../inc/tests.h"

int	tolower_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("\x1b[43;30m TOLOWER \x1b[0m\n");
	load_test(&testlist, "Basic test", &tolower_basic_test);
	load_test(&testlist, "NULL test", &tolower_null_test);
	load_test(&testlist, "Basic char variable test", &tolower_basic_var_test);
	return (launch_tests(&testlist));
}
