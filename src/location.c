#include <stdio.h>
#include <string.h>

struct Location {
	const char *description;
	const char *tag;
}locs[] = {
	{"A grassy meadow", "meadow"},
	{"The top of the hill", "hill"}
};


#define numberOfLocations (sizeof locs / sizeof *locs)

static unsigned currentLocation = 0;

void executeLook(const char *noun) {
	if (noun != NULL && strcmp(noun, "around") == 0) {
		printf("You are in %s.\n", locs[currentLocation].description);
	} else {
		printf("Nothing to look at there.\n");
	}
}

void executeGo(const char *noun) {
	unsigned i;
	for (i = 0; i < numberOfLocations; i++) {
		if (noun != NULL && strcmp(noun, locs[i].tag) == 0) {
			if (i == currentLocation) {
				printf("You are already at this location.\n");
			} else {
				printf("Ok.\n");
				currentLocation = i;
				executeLook("around");
			}
			return;
		}
	}
	printf("Where are you trying to go? Try again.\n");
}
