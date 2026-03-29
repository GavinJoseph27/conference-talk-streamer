# Conference Talk Streamer

A C++ application for organizing and streaming conference talks. Users can browse conferences, search talks by speaker or keyword, manage a playlist, and play talks with audio or video output.

## Features

- Browse and print all conferences and their talks
- Search talks by speaker, keyword, or both using a polymorphic Search hierarchy
- Manage a talk playlist with add and clear functionality
- Play talks in audio-only or audio+video mode using the Strategy pattern
- Factory pattern for creating Search objects at runtime
- Templated generic List class with operator overloading
- Zero memory leaks verified by Valgrind across all test cases

## Technical Highlights

- **Templates** — generic `List<T>` class with `+=`, `-=`, and `[]` operator overloading
- **Multiple Inheritance** — diamond Search hierarchy with virtual base classes (`S_Search`, `K_Search`, `SK_Search`)
- **Polymorphism** — abstract `Search` and `Player` base classes with runtime dispatch
- **Factory Pattern** — `SearchFactory` decouples Search object creation from application logic
- **Strategy Pattern** — `Player` interface swaps between `AudioPlayer` and `VideoPlayer` at runtime
- **Memory Management** — proper destructors and ownership chain with zero Valgrind errors

## Project Structure
```
├── main.cc              # Entry point
├── Control.h/cc         # Program flow and menu handling
├── View.h/cc            # User input and output
├── SummitStream.h/cc    # Central store for conferences and talks
├── Conference.h/cc      # Conference entity with talk collection
├── Talk.h/cc            # Talk entity with metadata and content
├── Search.h/cc          # Abstract search hierarchy (S, K, SK)
├── SearchFactory.h      # Factory for creating Search objects
├── Player.h/cc          # Abstract player with Audio and Video subclasses
├── List.h               # Templated generic list with operator overloading
├── TestControl.h/cc     # Automated test framework
└── Tester.h/cc          # Common test utilities
```

## Compilation
```bash
# Build both executables
make

# Run the interactive program
./a4

# Run automated tests
./a4test

# Clean compiled files
make clean
```

## Test Results

- Functional score: **22/22**
- Memory leaks: **0 bytes in 0 blocks** across all 6 test cases (verified by Valgrind)
