CC=g++
CFLAGS=--std=c++0x -Isrc
TESTFLAGS=
LDTESTFLAGS=-lgtest -lgtest_main -pthread
OBJECTS=$(wildcard bin/*.o)

all: Arbiter.o SimpleGame.o Deck.o BiddingConstraint.o Call.o Bidding.o Trick.o Hand.o DummyComputerPlayer.o Play.o Deal.o Application.o Player.o Printer.o ui_text_Hand.o ui_text_Deal.o ui_text_Play.o ui_text_Application.o ui_text_Bidding.o BridgeTCS Scorer.o

test: Standard52DeckTest BiddingConstraintTest BiddingTest
	bin/Standard52DeckTest
	bin/BiddingConstraintTest
	bin/BiddingTest

BridgeTCS: bin src/BridgeTCS.cpp src/model/Application.hpp src/ui/text/Application.hpp
	$(CC) $(CFLAGS) src/BridgeTCS.cpp $(OBJECTS) -o bin/BridgeTCS

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

Application.o: bin src/model/Application.cpp src/model/Application.hpp
	$(CC) $(CFLAGS) -c src/model/Application.cpp -o bin/Application.o

Player.o: bin src/ui/text/Player.cpp src/ui/text/Player.hpp
	$(CC) $(CFLAGS) -c src/ui/text/Player.cpp -o bin/Player.o

Printer.o: bin src/ui/text/Printer.cpp src/ui/text/Printer.hpp
	$(CC) $(CFLAGS) -c src/ui/text/Printer.cpp -o bin/Printer.o

ui_text_Hand.o: bin src/ui/text/Hand.cpp src/ui/text/Hand.hpp
	$(CC) $(CFLAGS) -c src/ui/text/Hand.cpp -o bin/ui_text_Hand.o

ui_text_Application.o: bin src/ui/text/Application.cpp src/ui/text/Application.hpp
	$(CC) $(CFLAGS) -c src/ui/text/Application.cpp -o bin/ui_text_Application.o
	
ui_text_Deal.o: bin src/ui/text/Deal.cpp src/ui/text/Deal.hpp
	$(CC) $(CFLAGS) -c src/ui/text/Deal.cpp -o bin/ui_text_Deal.o

ui_text_Play.o: bin src/ui/text/Play.cpp src/ui/text/Play.hpp
	$(CC) $(CFLAGS) -c src/ui/text/Play.cpp -o bin/ui_text_Play.o
	
ui_text_Bidding.o: bin src/ui/text/Bidding.cpp src/ui/text/Bidding.hpp
	$(CC) $(CFLAGS) -c src/ui/text/Bidding.cpp -o bin/ui_text_Bidding.o

SimpleGame.o: bin src/model/SimpleGame.cpp src/model/SimpleGame.hpp src/model/Game.hpp
	$(CC) $(CFLAGS) -c src/model/SimpleGame.cpp -o bin/SimpleGame.o

Scorer.o: bin src/model/Scorer.cpp src/model/Scorer.hpp
	$(CC) $(CFLAGS) -c src/model/Scorer.cpp -o bin/Scorer.o

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
