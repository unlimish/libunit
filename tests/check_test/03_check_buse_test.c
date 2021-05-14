#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include "../inc/tests.h"

int check_buse_test(void)
{
    if (ft_memcpy("abc", "def", 3))
        return (0);
    else
        return (-1);
}
