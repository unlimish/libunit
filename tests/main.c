#include "inc/tests.h"
#include "../framework/inc/libunit.h"

int	main(int argc, char **argv)
{
	char *func;

	puts("\n\n  ^~^  ,");
	puts(" ('Y') )");
	puts(" /   \\/  \x1b[36m\x1b[1m42 Unit Tests\x1b[0m\x1b[39m  __QQ");
	puts("(\\|||/)                (_)_\">>");
	puts("                      /\n");
	func = "strlen";
	if ( argc == 1 || 0 == strncmp(argv[1],func, strlen(func)))
		strlen_launcher();
	func = "toupper";
	if ( argc == 1 || 0 == strncmp(argv[1],func, strlen(func)))
		toupper_launcher();
	func = "tolower";
	if ( argc == 1 || 0 == strncmp(argv[1],func, strlen(func)))
		tolower_launcher();
	func = "atoi";
	if ( argc == 1 || 0 == strncmp(argv[1],func, strlen(func)))
		atoi_launcher();
	func = "check";
	if ( argc == 1 || 0 == strncmp(argv[1],func, strlen(func)))
		check_launcher();
}
