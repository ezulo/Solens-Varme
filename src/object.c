#include <stdio.h>
#include "object.h"

OBJECT objs[] = {
	//locations
	{"a grassy meadow", "meadow", NULL}, //0
	{"the top of the hill", "hill", NULL}, //1
	{"the woods", "woods", NULL}, //2
	//items
	{"damp stick", "stick", &objs[0]},
	{"log", "log", &objs[0]},
	{"butterfly", "butterfly", &objs[1]},
	//player
	{"yourself", "myself", &objs[0]}
};
