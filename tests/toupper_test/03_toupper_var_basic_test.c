#include <string.h>
#include "../inc/tests.h"

int toupper_basic_var_test(void)
{
	char	c;

	c = 'A';
	if (ft_toupper(c) == toupper(c))
		return (0);
	else
		return(-1);
}
