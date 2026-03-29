Name: Gavin Joseph
Student Number: 101348882

main.cc:
Starting point of the program. Runs the main menu and allows the user to interact with SummitStream. Users can view conferences, search talks by speaker or keyword, manage a playlist, and play talks with audio or video.

Control.h / Control.cc:
Handles program flow. Connects SummitStream, View, and SearchFactory. Initializes conferences and talks from file, handles menu selections, manages the talk playlist, and delegates to View for input/output.

View.h / View.cc:
Handles user input and output. Displays menus, prints conferences and talks, prompts for speaker and keyword selections, plays the playlist, and toggles between audio and video players.

Talk.h / Talk.cc:
Represents a conference talk. Stores title, speaker, keywords, audio content, and video filename. Provides getters, a keyword search function, and a print function.

Conference.h / Conference.cc:
Represents a conference. Stores name, description, and a collection of Talks. Provides functions to add talks, retrieve talks, print conference details, and compare by name.

SummitStream.h / SummitStream.cc:
Central store for all Conferences and their Talks. Provides functions to add conferences and talks, retrieve conferences by name or index, and search for talks matching a Search object.

Search.h / Search.cc:
Defines the abstract Search base class and three concrete search types. S_Search matches by speaker, K_Search matches by keyword, and SK_Search matches by speaker or keyword using multiple inheritance.

SearchFactory.h:
Creates and returns the appropriate Search object based on a type string. Separates object creation from application logic.

Player.h / Player.cc:
Defines the abstract Player base class and two concrete players. AudioPlayer outputs the talk audio string. VideoPlayer outputs the audio string and reads ASCII art from a file.

List.h:
Templated fixed-size dynamic array used to store collections of Conferences and Talks. Supports add (+=), remove (-=), indexed access ([]), clear, and size operations.

TestControl.h / TestControl.cc:
Contains automated testing code. Tests adding conferences and talks, searching by speaker, keyword, and speaker or keyword, and playing the playlist with video.

Tester.h / Tester.cc:
Provides common test functionality used by TestControl.

Compilation Instructions:
To compile the program, run:
make or make all

To clean the compiled files, run:
make clean

To run the program:
./a4

To run the automated tests:
./a4test