#include <string.h>
#include <stdio.h>
#include "../inc/tests.h"

int	atoi_int_max_test(void)
{
	if (ft_atoi("2147483647") == atoi("2147483647"))
		{
			return (0);
		}
	else
		return(-1);
}
