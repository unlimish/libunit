#include <string.h>
#include "../inc/tests.h"

int	toupper_basic_test(void)
{
	if (ft_toupper('a') == toupper('a'))
	{
		return (0);
	}
	else
		return (-1);
}
