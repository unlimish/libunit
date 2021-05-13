#include <string.h>
#include "../inc/tests.h"

int	strlen_basic_test(void)
{
	if (ft_strlen("abc") == strlen("abc"))
		return (0);
	else
		return(-1);
}
