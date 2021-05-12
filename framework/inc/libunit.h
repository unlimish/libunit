#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <sys/wait.h>
# include <signal.h>

# define OK 0;
# define KO -1;
# define SEGV -2;
# define BUSE -3;

typedef struct	s_unit_test
{
	int					(* func)();
	char				*title;
	char				*result;
	struct s_unit_test	*next;
}	t_unit_test;

void	load_test(t_unit_test **testlist, char *title, int (* test_func)());
int		launch_tests(t_unit_test **testlist);

#endif
