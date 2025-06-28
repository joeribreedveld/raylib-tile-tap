CC = gcc
CFLAGS = -I/opt/homebrew/opt/raylib/include
LDFLAGS = -L/opt/homebrew/opt/raylib/lib -lraylib -lm -lpthread -ldl
SRC = main.c tile.c game.c
OUT = tile_tap

all:
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
