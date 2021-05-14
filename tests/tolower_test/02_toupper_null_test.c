#include <string.h>
#include <stdio.h>
#include "../inc/tests.h"

int	tolower_null_test(void)
{
	if (ft_tolower(0) == tolower(0))
		return (0);
	else
		return (-1);
}
