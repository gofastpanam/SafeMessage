CC=gcc
CFLAGS=-Wall -Wextra -O2
TARGET=safemessage

all: $(TARGET)

$(TARGET): SafeMessage.c
	$(CC) $(CFLAGS) -o $(TARGET) SafeMessage.c

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: all clean
