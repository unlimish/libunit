#include "../inc/libunit.h"

void	load_test(t_unit_test **testlist, char *title, int (*test_func)())
{
	t_unit_test	*new;
	t_unit_test	*iter;

	printf("\x1b[32m.\x1b[0m");
	iter = *testlist;
	new = malloc(sizeof(t_unit_test));
	new->next = NULL;
	new->result = NULL;
	new->title = tf_strdup(title);
	new->func = test_func;
	if (!new)
		exit(0);
	if (*testlist == NULL)
		*testlist = new;
	else
	{
		while (iter->next)
			iter = iter->next;
		iter->next = new;
	}
}

int	execute_test(t_unit_test *iter)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		exit(0);
	if (pid == 0)
		exit(iter->func());
	wait(&status);
	if (WIFEXITED(status))
	{
		if (0 == status)
			iter->result = tf_strdup(OK);
		else
			iter->result = tf_strdup(KO);
	}
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			iter->result = tf_strdup(SEGV);
		if (WTERMSIG(status) == SIGBUS)
			iter->result = tf_strdup(BUSE);
	}
	return (0);
}

void	disp_result(t_unit_test *testlist)
{
	int	ok_cnt;
	int	all_cnt;

	ok_cnt = 0;
	all_cnt = 0;
	while (testlist)
	{
		all_cnt++;
		printf("> %-30s : %5s\n", testlist->title, testlist->result);
		if (tf_strcmp(OK, testlist->result) == 0)
			ok_cnt++;
		testlist = testlist->next;
	}
	if (ok_cnt == all_cnt)
		color(GREEN);
	printf("\x1b[1m%d/%d tests checkted\x1b[0m\n\n", ok_cnt, all_cnt);
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

int	launch_tests(t_unit_test **testlist)
{
	t_unit_test	*iter;

	iter = *testlist;
	while (iter)
	{
		execute_test(iter);
		iter = iter->next;
	}
	printf("\n");
	disp_result(*testlist);
	free_testlist(testlist);
	return (0);
}
