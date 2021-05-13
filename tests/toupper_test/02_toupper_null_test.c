#include <string.h>
#include <stdio.h>

int	toupper_null_test(void)
{
	if (ft_toupper(NULL) == toupper(NULL))
		{
			return (0);
		}
	else
		return(-1);
}
