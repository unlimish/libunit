#include "../../framework/inc/libunit.h"
#include "../inc/tests.h"

int	atoi_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("\x1b[43;30m ATOI \x1b[0m\n");
	load_test(&testlist, "Basic test", &atoi_basic_test);
	load_test(&testlist, "INT_MAX test", &atoi_int_max_test);
	load_test(&testlist, "INT_MIN test", &atoi_int_min_test);
	return (launch_tests(&testlist));
}
