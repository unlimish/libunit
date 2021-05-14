#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include "../inc/tests.h"

int	check_buse_test(void)
{
	FILE	*f;
	int		*m;

	f = tmpfile();
	m = (int *)mmap(0, 4, PROT_WRITE, MAP_PRIVATE, fileno(f), 0);
	if (m)
	{
		*m = 0;
		return (0);
	}
	else
		return (-1);
}
