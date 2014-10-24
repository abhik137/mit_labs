#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if (argc == 1) {
		printf("Usage: run <command> [<parameters>]\n");
		exit(1);
	}
	execvp(argv[1], &argv[1]);		// argv[1] => full cmd i.e 'ls -al .'
	printf("Sorry...   couldn't run that!\n");
	return 0;
}