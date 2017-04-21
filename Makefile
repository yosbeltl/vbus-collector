############
# Makefile #
############

# C source files
SOURCES = kbhit.c serial.c vbus.c sqlite.c main.c

# Optimization level, can be [0, 1, 2, 3, s].
OPT = 3

TARGET = vbus-collector

#===================================================================================

CC = gcc
CFLAGS = -std=gnu99 -O$(OPT) -c -Wall -D__SQLITE__
LDFLAGS = -lsqlite3
OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

REMOVE    = rm -f
REMOVEDIR = rm -rf
CREATEDIR = mkdir -p

# Object files directory
OBJDIR = obj

#===================================================================================

all: createdirs $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

createdirs:
	@$(CREATEDIR) $(OBJDIR)

clean:
	$(REMOVEDIR) $(OBJDIR)
	$(REMOVE) $(TARGET)
