#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include "../inc/libunit.h"

int test_atoi_0(void)
{
	printf("test_here!\n");
	if (0 == atoi("aaa_0"))
		return(0);
	return(1);
}

int test_atoi_1(void)
{
		printf("test_here!\n");
		if (1 == atoi("1aaa_0"))
			return(0);
		return(1);
}

int test_err(void)
{
	return(1);
}

int test_segv(void)
{
	char *a;

	a = NULL;
	*a = 'a';
	return(0);
}

void load_test(t_unit_test **testlist, char *title, int (* test_func)());
int launch_tests(t_unit_test **testlist);

size_t	ft_strlen(const char *s)
{
	size_t i;

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

void load_test(t_unit_test **testlist, char *title, int (* test_func)())
{
    t_unit_test *new;
	t_unit_test *iter;

	printf("title : [%s]\n", title);
	iter = *testlist;
    new = malloc(sizeof(t_unit_test));
	new->next = NULL;
	new->title = ft_strdup(title);
	new->func = test_func;
    if (!new)
        exit(0); //abort for malloc error;
    if (*testlist == NULL)
	{
		printf("koko\n");
        *testlist = new;
	}
    else
    {
		printf("kokoB\n");
        while (iter->next)
            iter = iter->next;
        iter->next = new;
    }
}

int launch_tests(t_unit_test **testlist) //freamwork(/*複数のテスト(の配列なり、リストなり)が引数*/)
{
    pid_t   pid;
    pid_t   wait_pid;
    int status;
	int ret;
	t_unit_test *tmp;

    while(*testlist)
    {
		printf("title:[%s]\n", (*testlist)->title);
        pid = fork();
        if(pid < 0)
            exit(0);
        if(pid == 0)
            exit((*testlist)->func());
		wait_pid = wait(&status);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
		if (WIFSIGNALED(status))
			ret = WTERMSIG(status);
		printf("ret: [%d]\n", ret);
		tmp = *testlist;
		*testlist = (*testlist)->next;
		free(tmp->title);
		free(tmp);
    }
    if (WIFEXITED(status))
        return ((char)WEXITSTATUS(status));
    if (WIFSIGNALED(status))
        return (WTERMSIG(status));
    return (0);
}

int main()
{
    t_unit_test *testlist;

    testlist = NULL;
    load_test(&testlist, "Test 0", test_atoi_0);
    load_test(&testlist, "Test 1", test_atoi_1);
    load_test(&testlist, "Test error", test_err);
    load_test(&testlist, "Test segv", test_segv);
    launch_tests(&testlist);
}
