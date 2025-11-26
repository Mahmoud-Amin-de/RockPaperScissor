# Rock Paper Scissors Game 🎮

A professional C++ console implementation of the classic Rock Paper Scissors game with colorful UI and multiple rounds support.

## Project Context

This project was developed as part of the **"Algorithms & Problem-Solving Level 2 Course"** by **Dr. Mohammed Abu-Hadhoud/Programming Advices**. The game concept was provided as a course exercise, but the entire code implementation, structure, and additional features were developed from scratch by me.

## Features

- **Classic Rock Paper Scissors** gameplay with proper rules
- **Multiple rounds** (1-10) per game session
- **Colorful console interface** with visual feedback
- **Detailed game statistics** and round history
- **Play-again functionality** for continuous gameplay
- **Real-time results** with winner highlighting
- **Sound effects** for computer wins
- **Input validation** for robust user experience

## Quick Start

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- Windows OS (for color support)

### Compile & Run
```bash
# Compile the project
g++ -o game main.cpp

# Run the game
./game
### Using Visual Studio
Open RockPaperScissor.sln in Visual Studio

Build the solution (Ctrl+Shift+B)

Run the program (F5)

## How to Play
Run the executable by typing ./game in your terminal

Enter number of rounds when prompted (choose between 1-10)

For each round, make your choice:

Type 1 for Rock ✊

Type 2 for Paper ✋

Type 3 for Scissors ✌️

View round results with color-coded winners (Green=Player, Red=Computer, Yellow=Draw)

See final statistics and overall winner after all rounds

Choose to play again by typing 'Y' or exit by typing 'N'

## Game Rules:

Rock crushes Scissors ✊ > ✌️

Scissors cuts Paper ✌️ > ✋

Paper covers Rock ✋ > ✊

Same choice results in a draw

## Project Structure:

RockPaperScissor/
├── main.cpp                 # Main game implementation
├── RockPaperScissor.sln     # Visual Studio solution file
├── RockPaperScissor.vcxproj # Project configuration
├── README.md                # Project documentation
├── LICENSE                  # MIT License
└── .gitignore              # Git ignore rules

## Code Architecture:

The project uses clean, modular C++ with:

Enum-based states for game choices and winners

Struct-based data management for game information

Randomized computer AI for fair gameplay

Color-coded UI for enhanced user experience

Input validation for error-free interaction

### Key Functions:

PlayGame() - Manages the main game flow

WhoWonTheRound() - Implements game rules logic

PrintRoundResults() - Displays colorful round outcomes

ShowFinalGameResults() - Shows comprehensive statistics

## UI/UX Features:

Clean console interface with proper formatting and tabs

Dynamic color changes based on game outcome:

Green: Player wins

Red: Computer wins (with beep sound)

Yellow: Draw rounds

Detailed round information showing both player and computer choices

Comprehensive game statistics including wins, draws, and final winner

Visual separation between different rounds and final results

## Contributing:

Contributions, issues, and feature requests are welcome! Feel free to check issues page if you want to contribute.

Fork the repository

Create a feature branch (git checkout -b feature/improvement)

Commit your changes (git commit -m 'Add some improvement')

Push to the branch (git push origin feature/improvement)

Open a Pull Request

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Author
Mahmoud Amin

GitHub: @Mahmoud-Amin-de

### Attribution

*Game concept inspired by "Algorithms & Problem-Solving Level 2 Course" by Dr. Mohammed Abu-Hadhoud/Programming Advices.
Code implementation, structure, and additional features developed from scratch by Mahmoud Amin.*

This project demonstrates fundamental C++ concepts including functions, data structures, control flow, and user interaction handling.
