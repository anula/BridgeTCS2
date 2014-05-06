CC=g++
CFLAGS=--std=c++0x -Isrc
TESTFLAGS=
LDTESTFLAGS=-lgtest -lgtest_main -pthread

all: BridgeTCS Deck.o BiddingConstraint.o Call.o Bidding.o Trick.o Play.o Hand.o

test: Standard52DeckTest BiddingConstraintTest BiddingTest
	bin/Standard52DeckTest
	bin/BiddingConstraintTest
	bin/BiddingTest

BridgeTCS: bin src/BridgeTCS.cpp src/Application.hpp src/ui/text/Application.hpp
	$(CC) $(CFLAGS) src/BridgeTCS.cpp -o bin/BridgeTCS

Arbiter.o: bin src/Arbiter.cpp src/Arbiter.hpp
	$(CC) $(CFLAGS) -c src/Arbiter.cpp -o bin/Arbiter.o

Deal.o: bin src/Deal.cpp src/Deal.hpp src/Deal.hpp src/Trick.hpp src/Play.hpp src/Trump.hpp
	$(CC) $(CFLAGS) -c src/Deal.cpp -o bin/Deal.o
	
Deck.o: bin src/Deck.cpp src/Deck.hpp
	$(CC) $(CFLAGS) -c src/Deck.cpp -o bin/Deck.o

Call.o: bin src/Call.cpp src/Call.hpp src/Trump.hpp
	$(CC) $(CFLAGS) -c src/Call.cpp -o bin/Call.o

Trick.o: bin src/Trick.cpp src/Trick.hpp src/Card.hpp src/Trump.hpp
	$(CC) $(CFLAGS) -c src/Trick.cpp -o bin/Trick.o
	
Bidding.o: bin src/Bidding.cpp src/Bidding.hpp src/Call.hpp src/BiddingConstraint.hpp src/Contract.hpp
	$(CC) $(CFLAGS) -c src/Bidding.cpp -o bin/Bidding.o

BiddingConstraint.o: bin src/BiddingConstraint.cpp src/BiddingConstraint.hpp src/Call.hpp src/Trump.hpp
	$(CC) $(CFLAGS) -c src/BiddingConstraint.cpp -o bin/BiddingConstraint.o
	
Hand.o: bin src/Hand.cpp src/Hand.hpp
	$(CC) $(CFLAGS) -c src/Hand.cpp -o bin/Hand.o

Standard52DeckTest: bin test/Standard52DeckTest.cpp Deck.o
	$(CC) $(CFLAGS) $(TESTFLAGS) test/Standard52DeckTest.cpp bin/Deck.o -o bin/Standard52DeckTest $(LDTESTFLAGS)

BiddingConstraintTest: bin test/BiddingConstraintTest.cpp Call.o BiddingConstraint.o
	$(CC) $(CFLAGS) $(TESTFLAGS) test/BiddingConstraintTest.cpp bin/BiddingConstraint.o bin/Call.o -o bin/BiddingConstraintTest $(LDTESTFLAGS)

BiddingTest: bin test/BiddingTest.cpp Call.o BiddingConstraint.o Bidding.o
	$(CC) $(CFLAGS) $(TESTFLAGS) test/BiddingTest.cpp bin/BiddingConstraint.o bin/Bidding.o bin/Call.o -o bin/BiddingTest $(LDTESTFLAGS)



clean:
	rm -r bin

bin:
	mkdir bin
