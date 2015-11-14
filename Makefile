CC = g++
OBJ = dice_game.o

dice_game: $(OBJ)
	$(CC) $^ -o $@
%.o: %.cxx
	$(CC) -std=gnu++11 -c -o $@ $^
clean:
	rm dice_game *.o
