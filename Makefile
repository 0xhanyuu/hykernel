# compiler information
CC = gcc
CFLAGS = -Wall -Wextra -std=gnu17 -I $(INCDIR)

# directories
INCDIR = include/
OBJDIR = obj/
SRCDIR = src/

# files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# target binary
TARGET = hykernel

# create all object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# link + create executable
all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# remove files
clean:
	rm -f $(TARGET) ${OBJS}

.PHONY: clean
