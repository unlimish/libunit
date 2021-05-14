#include "../../framework/inc/libunit.h"
#include "../inc/tests.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("\x1b[43;30m STRLEN \x1b[0m\n");
	load_test(&testlist, "Basic test", &strlen_basic_test);
	load_test(&testlist, "NULL test (expected: SEGV)", &strlen_null_test);
	load_test(&testlist, "Basic char variable test", &strlen_basic_var_test);
	color(RESET);
	return(launch_tests(&testlist));
}
