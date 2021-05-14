#include <string.h>
#include "../inc/tests.h"

int	atoi_basic_test(void)
{
	if (ft_atoi("123") == atoi("123"))
	{
		return (0);
	}
	else
		return (-1);
}
