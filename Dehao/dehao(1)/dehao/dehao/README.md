# Poker Card Game

A console-based poker card game with special cards and store features.

## Game Rules

1. **Game Start**
   - Enter your name to begin
   - Choose difficulty level (Easy, Medium, Difficult)
   - Each difficulty has different score requirements:
     - Easy: 100 points
     - Medium: 200 points
     - Difficult: 300 points

2. **Gameplay**
   - Each round, you can:
     - Play cards from your hand
     - Visit the store to purchase special cards
     - View deck status
     - End the round
   - Match pairs to earn points
   - Use special cards to boost your score

3. **Special Cards**
   - Bonus Cards: Add points to your score
   - Multiplier Cards: Multiply your current score
   - Wild Cards: Can be used as any card

4. **Store System**
   - Earn coins by completing rounds
   - Use coins to purchase special cards
   - Manage your special cards inventory

5. **Scoring**
   - Earn points by matching pairs
   - Special cards can boost your score
   - High scores are tracked

## Building and Running

### Prerequisites
- C++11 or later
- Make
- g++ compiler

### Building the Game
```bash
# Build the main game
make

# Build and run all tests
make test

# Clean build files
make clean
```

### Running the Game
```bash
# Run the game
./game
```

### Running Tests
```bash
# Run all tests
make test

# Run specific tests
./test_card
./test_deck
./test_player
./test_game
```

## Testing

The game includes comprehensive unit tests for:
- Card class
- Deck class
- Player class
- Game class

Tests cover:
- Card creation and validation
- Deck shuffling and dealing
- Player score management
- Special card effects
- Game flow and round management
- Store interactions
- Save/Load functionality

## Error Handling

The game includes robust error handling for:
- Invalid card operations
- Invalid player inputs
- Game state management
- File operations

## Contributing

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request 