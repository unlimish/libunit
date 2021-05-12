#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include "../inc/libunit.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != 0)
		i++;
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		strlen;
	char	*return_p;
	char	*dest;

	strlen = ft_strlen(s1);
	return_p = malloc(sizeof(char) * strlen + 1);
	if (!return_p)
		return (return_p);
	dest = return_p;
	while (*s1)
		*dest++ = *s1++;
	*dest = 0;
	return (return_p);
}

void	load_test(t_unit_test **testlist, char *title, int (*test_func)())
{
	t_unit_test	*new;
	t_unit_test	*iter;

	printf("title : [%s]\n", title);
	iter = *testlist;
    new = malloc(sizeof(t_unit_test));
	new->next = NULL;
	new->result = NULL;
	new->title = ft_strdup(title);
	new->func = test_func;
    if (!new)
        exit(0); //abort for malloc error;
    if (*testlist == NULL)
        *testlist = new;
    else
    {
        while (iter->next)
            iter = iter->next;
        iter->next = new;
    }
}

int	launch_tests(t_unit_test **testlist) //freamwork(/*複数のテスト(の配列なり、リストなり)が引数*/)
{
	pid_t	pid;
	int	status;
	int	ret;
	t_unit_test	*iter;

	iter = *testlist;
    while (iter)
    {
        pid = fork();
        if (pid < 0)
            exit(0);
        if (pid == 0)
            exit(iter->func());
		wait(&status);
		if (WIFEXITED(status))
		{
			if (!!WEXITSTATUS(status))
				iter->result = ft_strdup("OK");
			else
				iter->result = ft_strdup("KO");
		}
		if (WIFSIGNALED(status))
		{
			ret = WTERMSIG(status);
			if (ret == SIGSEGV)
				iter->result = ft_strdup("SEGV");
			if (ret == SIGBUS)
				iter->result = ft_strdup("BUSE");
		}
		iter = iter->next;
    }
    return (0);
}

void	disp_result(t_unit_test *testlist)
{
	int	ok_cnt;
	int	all_cnt;

	ok_cnt = 0;
	all_cnt = 0;
	while(testlist)
    {
		all_cnt++;
		printf("> %s : [%s]\n",testlist->title, testlist->result);
		if (ft_strcmp("OK", testlist->result))
			ok_cnt++;
		testlist = testlist->next;
	}
	printf("%d/%d tests checkted\n", ok_cnt, all_cnt);
}

void	free_testlist(t_unit_test **testlist)
{
	t_unit_test	*iter_tmp;
	t_unit_test	*iter;
	
	if (!testlist)
		return ;
	iter = *testlist;
	while (iter)
	{
		iter_tmp = iter;
		iter = iter->next;
		free(iter_tmp->result);
		free(iter_tmp->title);
		free(iter_tmp);
	}
}
