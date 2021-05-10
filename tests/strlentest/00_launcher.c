#include "../../framework/inc/libunit.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;
	puts("STRLEN:");
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "Basic char variable test", &basic_var_test);
	load_test(&testlist, "NULL test", &null_test);
	return(launch_tests(&testlist));
}
