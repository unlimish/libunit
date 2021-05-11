#include "../../framework/inc/libunit.h"
#include "../inc/tests.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	puts("STRLEN:");
	load_test(&testlist, "Basic test", &strlen_basic_test);
	load_test(&testlist, "NULL test", &strlen_null_test);
	load_test(&testlist, "Basic char variable test", &strlen_basic_var_test);
	return(launch_tests(&testlist));
}
