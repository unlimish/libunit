#include <string.h>
#include "../inc/tests.h"

int	check_ko_test(void)
{
	if (ft_strlen("123") == strlen("1"))
	{
		return (0);
	}
	else
		return (-1);
}
