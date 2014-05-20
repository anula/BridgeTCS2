CC=g++
CFLAGS=--std=c++0x -Isrc
TESTFLAGS=
LDTESTFLAGS=-lgtest -lgtest_main -pthread

all: Arbiter.o Deck.o BiddingConstraint.o Call.o Bidding.o Trick.o Hand.o DummyComputerPlayer.o Play.o Deal.o Application.o BridgeTCS

test: Standard52DeckTest BiddingConstraintTest BiddingTest
	bin/Standard52DeckTest
	bin/BiddingConstraintTest
	bin/BiddingTest

BridgeTCS: bin src/BridgeTCS.cpp src/Application.hpp src/ui/text/Application.hpp 
	$(CC) $(CFLAGS) src/BridgeTCS.cpp bin/Application.o bin/DummyComputerPlayer.o bin/Call.o -o bin/BridgeTCS

Arbiter.o: bin src/model/Arbiter.cpp src/model/Arbiter.hpp
	$(CC) $(CFLAGS) -c src/model/Arbiter.cpp -o bin/Arbiter.o

Deal.o: bin src/model/Deal.cpp src/model/Deal.hpp src/model/Trick.hpp src/model/Play.hpp src/model/Trump.hpp
	$(CC) $(CFLAGS) -c src/model/Deal.cpp -o bin/Deal.o
	
Deck.o: bin src/model/Deck.cpp src/model/Deck.hpp
	$(CC) $(CFLAGS) -c src/model/Deck.cpp -o bin/Deck.o

Call.o: bin src/model/Call.cpp src/model/Call.hpp src/model/Trump.hpp
	$(CC) $(CFLAGS) -c src/model/Call.cpp -o bin/Call.o
	
Play.o: bin src/model/Play.cpp src/model/Play.hpp src/model/Trump.hpp src/model/Trick.hpp
	$(CC) $(CFLAGS) -c src/model/Play.cpp -o bin/Play.o

Trick.o: bin src/model/Trick.cpp src/model/Trick.hpp src/model/Card.hpp src/model/Trump.hpp
	$(CC) $(CFLAGS) -c src/model/Trick.cpp -o bin/Trick.o
	
Bidding.o: bin src/model/Bidding.cpp src/model/Bidding.hpp src/model/Call.hpp src/model/BiddingConstraint.hpp src/model/Contract.hpp
	$(CC) $(CFLAGS) -c src/model/Bidding.cpp -o bin/Bidding.o

BiddingConstraint.o: bin src/model/BiddingConstraint.cpp src/model/BiddingConstraint.hpp src/model/Call.hpp src/model/Trump.hpp
	$(CC) $(CFLAGS) -c src/model/BiddingConstraint.cpp -o bin/BiddingConstraint.o
	
Hand.o: bin src/model/Hand.cpp src/model/Hand.hpp
	$(CC) $(CFLAGS) -c src/model/Hand.cpp -o bin/Hand.o

DummyComputerPlayer.o: bin src/model/DummyComputerPlayer.cpp src/model/DummyComputerPlayer.hpp src/model/IPlayer.hpp
	$(CC) $(CFLAGS) -c src/model/DummyComputerPlayer.cpp -o bin/DummyComputerPlayer.o

Application.o: bin src/Application.cpp src/Application.hpp
	$(CC) $(CFLAGS) -c src/Application.cpp -o bin/Application.o

#SimpleGame.o: src/SimpleGame.cpp src/SimpleGame.hpp src/model/Game.hpp
#	$(CC) $(CFLAGS) -c src/SimpleGame.cpp -o bin/SimpleGame.o

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
