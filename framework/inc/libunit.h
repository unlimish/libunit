#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <sys/wait.h>
# include <signal.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define OK "\x1b[32m  OK \x1b[0m"
# define KO "\x1b[31m  KO \x1b[0m"
# define SEGV "\x1b[41;37m SEGV \x1b[0m"
# define BUSE "\x1b[45;37m BUSE \x1b[0m"

# define RED 31
# define GREEN 32
# define BROWN 33
# define BLUE 34
# define PURPLE 35
# define SKY 36
# define WHITE 37
# define RESET 0
# define BOLD 1

typedef struct s_unit_test
{
	int					(*func)();
	char				*title;
	char				*result;
	struct s_unit_test	*next;
}	t_unit_test;

void	load_test(t_unit_test **testlist, char *title, int (*test_func)());
int		launch_tests(t_unit_test **testlist);
int		tf_strcmp(const char *s1, const char *s2);
size_t	tf_strlen(const char *s);
char	*tf_strdup(const char *s1);

#endif
