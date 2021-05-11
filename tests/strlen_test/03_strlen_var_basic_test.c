#include <string.h>

int strlen_basic_var_test(void)
{
	char	*string;

	string = "Answer to the Ultimate Question of Life, the Universe, and Everything";
	if (ft_strlen(string) == strlen(string))
		return (0);
	else
		return(-1);
}
