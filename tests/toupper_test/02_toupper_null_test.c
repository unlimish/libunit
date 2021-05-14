#include <string.h>
#include <stdio.h>
#include "../inc/tests.h"

int	toupper_null_test(void)
{
	if (ft_toupper(0) == toupper(0))
	{
		return (0);
	}
	else
		return (-1);
}
