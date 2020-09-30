#include <stdio.h>
#include "object.h"

int listObjectsAtLocation(OBJECT *location) {
	OBJECT *obj = NULL;
	int count = 0;
	printf("You see:\n");
	for (obj = objs; obj < endOfObjs; obj++) {
		if (obj != player && obj->location == location) {
			count++;
			printf(" - %s\n", obj->description);
		}
	}
	if (count == 0) {
		printf("Nothing.\n");
	}
	return count;
}
