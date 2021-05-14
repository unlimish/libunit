#include <string.h>
#include "../inc/tests.h"

int	strlen_null_test(void)
{
	char	*nu;

	nu = NULL;
	if (ft_strlen((char *)nu) == strlen((char *)nu))
		return (0);
	else
		return (-1);
}
