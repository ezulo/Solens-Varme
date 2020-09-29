#include <stdio.h>
#include <stdbool.h>
#include "parseexec.h"

static char input[100] = "look around";

static bool getInput(void) {
	printf("\n--> ");
	return fgets(input, sizeof input, stdin) != NULL;
}

int main(void) {
	printf("You awaken in a grassy meadow, your wool shirt glistening with morning dew.\n");
	while (parseAndExecute(input) && getInput());
	printf("Goodbye.\n");
	return 0;
}
