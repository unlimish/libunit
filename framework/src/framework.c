#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int test_atoi_1(void)
{
    if (0 == atoi("aaa_0"))
        return(0);
    return(1);
}

void load_test(t_unit_test **testlist, char *title, int (* test_func)());
int launch_tests(t_unit_test **testlist);

void load_test(t_unit_test **testlist, char *title, int (* test_func)())
{
    t_unit_test *new;

    new = malloc(sizeof(t_unit_test));
    if (!new)
        exit(0); //abort for malloc error;
    if (testlist == NULL)
        *testlist = new;
    else
    {
        while ((*testlist)->next)
            *testlist = (*testlist)->next;
        (*testlist)->next = new;
    }
}

int launch_tests(t_unit_test **testlist) //freamwork(/*複数のテスト(の配列なり、リストなり)が引数*/)
{
    pid_t   pid;
    pid_t   wait_pid;
    int status;

    while(*testlist)
    {
        pid = fork();
        if(pid < 0)
            exit(0);
        if(pid == 0)
            exit((*testlist)->func());
        wait_pid = wait(&status);
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
    load_test(&testlist, "Test 1", test_atoi_1);
    launch_tests(&testlist);

//    printf("return from freamwork[%d]\n", freamwork());

    //printf("%d\n", ret);
}
