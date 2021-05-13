#include "../../framework/inc/libunit.h"
#include "../inc/tests.h"

int	toupper_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("\x1b[43;30m TOUPPER \x1b[0m\n");
	load_test(&testlist, "Basic test", &toupper_basic_test);
	load_test(&testlist, "NULL test", &toupper_null_test);
	load_test(&testlist, "Basic char variable test", &toupper_basic_var_test);
	return(launch_tests(&testlist));
}
