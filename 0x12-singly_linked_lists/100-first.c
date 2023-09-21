#include <stdio.h>

/**
 * pre_main - Constructor function to print a message before main.
 */
void __attribute__((constructor)) pre_main(void)
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
