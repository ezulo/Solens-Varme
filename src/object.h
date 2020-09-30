#include <stddef.h>

typedef struct object {
	const char *description;
	const char *tag;
	struct object *location;
} OBJECT;

extern OBJECT objs[];

#define meadow 		(objs + 0)
#define hill		(objs + 1)
#define woods		(objs + 2)
#define stick		(objs + 3)
#define log			(objs + 4)
#define butterfly	(objs + 5)
#define player		(objs + 6)

#define endOfObjs	(objs + 7)
