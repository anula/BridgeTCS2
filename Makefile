CC=g++
CFLAGS=--std=c++0x
TESTFLAGS=-Isrc
LDTESTFLAGS=-lgtest -lgtest_main -pthread

all: Deck.o BiddingConstraint.o Call.o

test: Standard52DeckTest BiddingConstraintTest 
	bin/Standard52DeckTest
	bin/BiddingConstraintTest

Deck.o: bin src/Deck.cpp src/Deck.hpp
	$(CC) $(CFLAGS) -c src/Deck.cpp -o bin/Deck.o

Call.o: bin src/Call.cpp src/Call.hpp src/Trump.hpp
	$(CC) $(CFLAGS) -c src/Call.cpp -o bin/Call.o

BiddingConstraint.o: bin src/BiddingConstraint.cpp src/BiddingConstraint.hpp src/Call.hpp src/Trump.hpp
	$(CC) $(CFLAGS) -c src/BiddingConstraint.cpp -o bin/BiddingConstraint.o

Standard52DeckTest: bin test/Standard52DeckTest.cpp Deck.o
	$(CC) $(CFLAGS) $(TESTFLAGS) test/Standard52DeckTest.cpp bin/Deck.o -o bin/Standard52DeckTest $(LDTESTFLAGS)

BiddingConstraintTest: bin test/BiddingConstraintTest.cpp Call.o
	$(CC) $(CFLAGS) $(TESTFLAGS) test/BiddingConstraintTest.cpp bin/BiddingConstraint.o bin/Call.o -o bin/BiddingConstraintTest $(LDTESTFLAGS)

clean:
	rm -r bin

bin:
	mkdir bin
