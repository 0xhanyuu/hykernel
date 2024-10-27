# compiler information
CC = gcc
CFLAGS = -Wall -Wextra -std=gnu17 -I ./include

# directories
INCDIR = include/
OBJDIR = obj/
SRCDIR = src/

# files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# create all object files
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# link + create executable
all: $(OBJS) 
	$(CC) $(CFLAGS) -o hykernel $(OBJS) 

# remove files
clean:
	rm -f hykernel ${OBJS}

.PHONY: clean
