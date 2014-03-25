CC=g++
CFLAGS=--std=c++11 -Isrc/
TESTFLAGS=-Isrc
LDTESTFLAGS=-lgtest -lgtest_main -pthread

all: Deck.o

test: Standard52DeckTest
	bin/Standard52DeckTest

Deck.o: bin src/Deck.cpp src/Deck.hpp
	$(CC) $(CFLAGS) -c src/Deck.cpp -o bin/Deck.o

Standard52DeckTest: bin test/Standard52DeckTest.cpp Deck.o
	$(CC) $(CFLAGS) $(TESTFLAGS) test/Standard52DeckTest.cpp bin/Deck.o -o bin/Standard52DeckTest $(LDTESTFLAGS)

clean:
	rm -r bin

bin:
	mkdir bin
