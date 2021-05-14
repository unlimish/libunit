#include <string.h>
#include "../inc/tests.h"

int tolower_basic_var_test(void)
{
	char	c;

	c = 'a';
	if (ft_tolower(c) == tolower(c))
		return (0);
	else
		return(-1);
}
