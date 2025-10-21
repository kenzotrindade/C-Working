CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system
TARGET = pokemon
SRCS = pokemon.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

re: clean all
