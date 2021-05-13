#include <string.h>
#include "../inc/tests.h"

int toupper_basic_var_test(void)
{
	char	*string;

	string = "Answer to the Ultimate Question of Life, the Universe, and Everything";
	if (ft_toupper(string) == toupper(string))
		return (0);
	else
		return(-1);
}
