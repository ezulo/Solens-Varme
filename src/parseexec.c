#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "location.h"

bool parseAndExecute(char* input) {
	char *verb = strtok(input, " \n");
	char *noun = strtok(NULL, " \n");
	if (verb != NULL) {
		if (strcmp(verb, "quit") == 0) {
			return false;
		} else if (strcmp(verb, "look") == 0) {
			printf("\n");
			executeLook(noun);
		} else if (strcmp(verb, "go") == 0) {
			printf("\n");
			executeGo(noun);
		} else {
			printf("Unknown command.\n");
		}
	}
	return true;
}
