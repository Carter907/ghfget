#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int main(int argc, char* argv[]) {

	if (argc != 4) {
		fprintf(stderr, "failed to provide correct number of arguments\n");
		exit(EXIT_FAILURE);
	}
	
	[[maybe_unused]]char * user = argv[1];
	[[maybe_unused]]char * repo = argv[2];
	[[maybe_unused]]char * path = argv[3];

	char *command = malloc(sizeof(char) * 1024);

	if (!command) {
		fprintf(stderr, "failed to allocate command string\n");
		exit(EXIT_FAILURE);
	}

	strcpy(command, "gh api repos/");

	command = strcat(command, user);
	command = strcat(command, "/");
	command = strcat(command, repo);
	command = strcat(command, "/contents/");
	command = strcat(command, path);
	command = strcat(command, " -H \"Accept: application/vnd.github.raw\"");

	int st = system(command);
	
	if (st == -1) {
		perror("failed to execute shell command");
		exit(EXIT_FAILURE);
	}
	
	return EXIT_SUCCESS;
}
