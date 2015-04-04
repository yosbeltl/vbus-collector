CC=gcc
CFLAGS=-D__SQLITE__ -O3 -c -Wall
LDFLAGS=-lsqlite3
SOURCES=kbhit.c checksum.c serial.c vbus.c sqlite.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=vbus-collector

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
	rm $(EXECUTABLE)