#include "../../framework/inc/libunit.h"
#include "../inc/tests.h"

int	check_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("\x1b[43;30m check \x1b[0m\n");
	load_test(&testlist, "OK test", &check_ok_test);
	load_test(&testlist, "KO test", &check_ko_test);
	load_test(&testlist, "SEGV test", &check_segv_test);
	load_test(&testlist, "BUSE test", &check_buse_test);
	return(launch_tests(&testlist));
}
