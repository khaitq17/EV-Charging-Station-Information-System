
TARGET = main


HEADER_DIR = include
SOURCE_DIR = source


SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)


CC = gcc
CFLAGS = -I$(HEADER_DIR) -Wall -Wextra


all: $(TARGET)


$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^


$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<


run: $(TARGET)
	./$(TARGET)


clean:
	del /Q $(subst /,\,$(SOURCE_DIR)\*.o) $(TARGET).exe


.PHONY: all clean
