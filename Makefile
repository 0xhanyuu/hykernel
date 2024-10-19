# compiler information
CC = gcc
CFLAGS = -Wall -I ./include

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
	$(CC) $(CFLAGS) -o main $(OBJS) 

# remove files
clean:
	rm -f main hykernel_directory ${OBJDIR}

.PHONY: clean
