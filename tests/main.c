#include "inc/tests.h"
#include "../framework/inc/libunit.h"

int	main(int argc, char **argv)
{
	char *func;

	puts("\n\n  ^~^  ,");
	puts(" ('Y') )");
	puts(" /   \\/  \x1b[36;1;4m42 Unit Tests\x1b[0m\x1b[39m  __QQ");
	puts("(\\|||/)                (_)_\">>");
	puts("                      /\n");
	func = "strlen";
	if ( argc == 1 || 0 == strncmp(argv[1],func, strlen(func) + 1))
		strlen_launcher();
	func = "toupper";
	if ( argc == 1 || 0 == strncmp(argv[1],func, strlen(func) + 1))
		toupper_launcher();
	func = "tolower";
	if ( argc == 1 || 0 == strncmp(argv[1],func, strlen(func) + 1))
		tolower_launcher();
	func = "atoi";
	if ( argc == 1 || 0 == strncmp(argv[1],func, strlen(func) + 1))
		atoi_launcher();
	func = "check";
	if ( argc == 1 || 0 == strncmp(argv[1],func, strlen(func) + 1))
		check_launcher();
}
