#include <string.h>
#include "../inc/tests.h"

int	tolower_basic_test(void)
{
	if (ft_tolower('A') == tolower('A'))
	{
		return (0);
	}
	else
		return(-1);
}
