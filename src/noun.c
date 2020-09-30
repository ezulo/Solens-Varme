#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "object.h"

bool hasTag(OBJECT *obj, const char *tag) {
	return tag != NULL && *tag != '\0' && strcmp(tag, obj->tag) == 0;
}

static OBJECT *getObject(const char *noun) {
	OBJECT *obj, *res = NULL;
	for (obj = objs; obj < endOfObjs; obj++) {
		if (hasTag(obj, noun)) {
			res = obj;
		}
	}
	return res;
}

OBJECT *getVisible(const char *intention, const char *noun) {
	// outputs a message if no object matches noun, or object is not visible from where player is
	OBJECT *obj = getObject(noun);
	if (obj == NULL) {
		printf("Unknown intention: %s\n", intention);
	} else if (!(
		// object is player
		   obj == player
		// object is the player's location
		|| obj == player->location
		// object is in player's locaiton
		|| obj->location == player->location
		// object is player's posession
		|| obj->location == player
		// object is a location
		// FIXME: no restrictions on this currently, that will change..
		|| obj->location == NULL
		// object is inside object in same location as player
		|| obj->location->location == player->location
		// object is inside object in posession of player
		|| obj->location->location == player
	)) {
		printf("You don't see any %s here.\n", noun);
		obj = NULL;
	}
	return obj;
}
