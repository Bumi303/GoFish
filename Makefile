CC=g++
EXE_FILE=r
all: $(EXE_FILE)

$(EXE_FILE): pokemon.o pokemon.h run_pokemon.cpp
	$(CC) pokemon.o run_pokemon.cpp -o $(EXE_FILE)
	
pokemon.o: pokemon.h pokemon.cpp
	$(CC) -c pokemon.cpp
