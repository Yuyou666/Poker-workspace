CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
TEST_CXXFLAGS = $(CXXFLAGS) -DTESTING

# Source files
SRCS = main.cpp Card.cpp Deck.cpp Player.cpp Game.cpp Round.cpp ScoreBoard.cpp Store.cpp CardGroup.cpp CardOnHand.cpp
TEST_SRCS = tests/test_card.cpp tests/test_deck.cpp tests/test_player.cpp tests/test_game.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Executables
MAIN = game
TEST_CARD = test_card
TEST_DECK = test_deck
TEST_PLAYER = test_player
TEST_GAME = test_game

# Default target
all: $(MAIN)

# Main game executable
$(MAIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Test executables
test_card: tests/test_card.o Card.o
	$(CXX) $(TEST_CXXFLAGS) -o $@ $^

test_deck: tests/test_deck.o Deck.o Card.o CardGroup.o
	$(CXX) $(TEST_CXXFLAGS) -o $@ $^

test_player: tests/test_player.o Player.o Card.o Deck.o CardGroup.o CardOnHand.o
	$(CXX) $(TEST_CXXFLAGS) -o $@ $^

# Special rule for Game.o when building test_game
test_game_Game.o: Game.cpp
	$(CXX) $(TEST_CXXFLAGS) -c $< -o $@

test_game: tests/test_game.o test_game_Game.o Player.o Card.o Deck.o Round.o ScoreBoard.o Store.o CardGroup.o CardOnHand.o
	$(CXX) $(TEST_CXXFLAGS) -o $@ $^

# Run all tests
test: test_card test_deck test_player test_game
	@echo "Running Card tests..."
	./test_card
	@echo "\nRunning Deck tests..."
	./test_deck
	@echo "\nRunning Player tests..."
	./test_player
	@echo "\nRunning Game tests..."
	./test_game

# Clean up
clean:
	rm -f $(MAIN) $(TEST_CARD) $(TEST_DECK) $(TEST_PLAYER) $(TEST_GAME) *.o tests/*.o test_game_Game.o

# Dependencies
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Test object files need TESTING macro
tests/%.o: tests/%.cpp
	$(CXX) $(TEST_CXXFLAGS) -c $< -o $@

# Phony targets
.PHONY: all test clean 