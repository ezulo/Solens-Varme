#include <stdio.h>
#include <string.h>
#include "object.h"
#include "noun.h"
#include "misc.h"

void executeLook(const char *noun) {
	if (noun != NULL && strcmp(noun, "around") == 0) {
		printf("You are in %s.\n", player->location->description);
		listObjectsAtLocation(player->location);
	} else {
		printf("Nothing to look at there.\n");
	}
}

void executeGo(const char *noun) {
	// iterate objects
	// if object tag matches noun, and object is a location, move there
	OBJECT *locationObj = NULL;
	for (locationObj = objs; locationObj++; locationObj < endOfObjs) {
		if (
				locationObj->location == NULL
				&&
				hasTag(locationObj, noun)
		) {
			if (player->location == locationObj) {
				printf("You are already at %s.\n", locationObj->description);
			} else {
				printf("OK.\n");
				player->location = locationObj;
			}
			executeLook("around");
			return;
		}
	}
	printf("Where are you trying to go?");
}
