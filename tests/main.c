#include "inc/tests.h"
#include "inc/utils.h"
#include "../framework/inc/libunit.h"

int	main(int argc, char **argv)
{
	int	list_len;
	int pass_len;
	t_unit_test	*testlist;

	puts("  ^~^  ,");
	puts(" ('Y') )");
	puts(" /   \\/  \x1b[36m\x1b[1m42 Unit Tests\x1b[0m\x1b[39m  __QQ");
	puts("(\\|||/)                (_)_\">>");
	puts("                      /");
	if ( argc == 1 || 0 == strncmp(argv[1],"strlen", strlen("strlen")))
		strlen_launcher();
	toupper_launcher();


}
