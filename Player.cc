#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"

using namespace std;

// Outputs the talk's audio string to the stream
void AudioPlayer::play(const Talk& m, ostream& ost){
    ost << m.getAudio() << endl;
}

// Outputs audio string then reads and prints the video file line by line
void VideoPlayer::play(const Talk& m, ostream& ost){
    ost << m.getAudio() << endl;
    ifstream myfile(m.getVideoFile()); // open ASCII art file
    string line;
    while(getline (myfile, line)) {
        ost << line << endl;
    }
}