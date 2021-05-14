#ifndef TESTS_H
# define TESTS_H
# include <ctype.h>
# include <stdlib.h>

# include "../../real_tests/libft/libft.h"

int	strlen_launcher(void);
int	strlen_basic_test(void);
int	strlen_null_test(void);
int	strlen_basic_var_test(void);

int	toupper_launcher(void);
int	toupper_basic_test(void);
int	toupper_null_test(void);
int	toupper_basic_var_test(void);

int	tolower_launcher(void);
int	tolower_basic_test(void);
int	tolower_null_test(void);
int	tolower_basic_var_test(void);

int	atoi_launcher(void);
int	atoi_basic_test(void);
int	atoi_int_max_test(void);
int	atoi_int_min_test(void);

int	check_launcher(void);
int	check_ok_test(void);
int	check_ko_test(void);
int	check_segv_test(void);
int	check_buse_test(void);
#endif
