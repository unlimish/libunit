#include <string.h>

int	strlen_null_test(void)
{
	if (ft_strlen(NULL) == strlen(NULL))
		return (0);
	else
		return(-1);
}
