#include <string.h>
#include "../inc/tests.h"

int atoi_int_min_test(void)
{
	char	*c;

	c = "-2147483648";
	if (ft_atoi(c) == atoi(c))
		return (0);
	else
		return(-1);
}
