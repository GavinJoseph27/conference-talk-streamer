#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Talk.h"

using namespace std;

// Abstract base class defining the play interface
class Player {
    public:
        virtual void play(const Talk& m, ostream& ost) = 0; // plays Talk to given stream
};

// Outputs audio content only
class AudioPlayer : public Player {
    public:
        virtual void play(const Talk& m, ostream& ost);
};

// Outputs audio content and ASCII art video from file
class VideoPlayer : public AudioPlayer {
    public:
        virtual void play(const Talk& m, ostream& ost);
};

#endif