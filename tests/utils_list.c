#include "inc/utils.h"
#include "../framework/inc/libunit.h"

int	cout_list_len(t_unit_test *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
