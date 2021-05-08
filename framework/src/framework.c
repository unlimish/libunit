#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int test()
{
    char *s = "aiueo";
    return (0);
}

int freamwork()
{
    pid_t   pid;
    int status;

    pid = fork();
    if(pid < 0)
        exit(0);
    if(pid == 0)
        exit(test());
    /*
    wait(&status);
    if (WIFEXITED(status))
        return ((char)WEXITSTATUS(status));
    if (WIFSIGNALED(status))
        return (WTERMSIG(status));
    */
    return (0);
}

int main()
{
    printf("return from freamwork[%d]\n", freamwork());

    //printf("%d\n", ret);
}