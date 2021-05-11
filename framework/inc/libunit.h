#ifndef LIBUNIT_H
#define LIBUNIT_H

#include <sys/wait.h>
#include <signal.h>

# define OK 0;
# define KO -1;
# define SEGV -2;
# define BUSE -3;

typedef struct		s_unit_test
{
    int					(* func)();
    char				*title;
    struct s_unit_test	*next;
}					t_unit_test;

#endif
