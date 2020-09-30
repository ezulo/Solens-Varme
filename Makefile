CFLAGS = -Wall -Werror
SHELL = /bin/sh
CC = cc
INCDIR = include
SRCDIR = src
OBJDIR = build

OBJECTS = $(addprefix $(OBJDIR)/, main.o parseexec.o location.o object.o noun.o misc.o)

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main 

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c $^ -o $@

clean:
	rm -f main $(OBJDIR)/*
