/* program to demonstrate usage of 'readdir()' and other directory functions */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	DIR *dip;
	struct dirent *dit;

	int i = 0;
	/* check to see if user entered a directory name */
	if (argc < 2) {
		printf("Usage: %s <directory>\n", argv[0]);
		return 0;
	}
	/*
	 * DIR *opendir (const char *name);
	 *
	 * Open a directory stream to argv[1] and make sure
	 * it's a readable and valid directory
	 */
	if ((dip = opendir(argv[1])) == NULL) {
		perror("opendir");
		return 0;
	}

	printf("Directory stream is now open\n");

	/*
	 * struct dirent *readdir(DIR *dir);
	 *
	 * Read in files from argv[1] and print
	 */
	while ((dit = readdir(dip)) != NULL) {
		i++;
		printf("\n%s", dit->d_name);
	}

	printf("\n\nreaddir() found a total of %d files\n", i);

	/*
	 * int closedir(DIR *dir);
	 * close the stream to argv[1] and check for errors.
	 */
	if (closedir(dip) == -1) {
		perror("closedir");
		return 0;
	}
	printf("Directory stream is now closed!\n");
	return 1;
}

/* References:
	http://www.thegeekstuff.com/2012/06/c-directory/
*/