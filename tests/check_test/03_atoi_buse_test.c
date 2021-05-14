#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include "../inc/tests.h"

int check_buse_test(void)
{
	FILE *f = tmpfile();
    int *m = (int*)mmap(0, 4, PROT_WRITE, MAP_PRIVATE, fileno(f), 0);
    *m = 0;
    return (0);
}
