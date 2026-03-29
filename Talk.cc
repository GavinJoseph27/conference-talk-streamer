#include <iostream>
#include <string>
using namespace std;

#include "Talk.h"

// Initializes all members in order
Talk::Talk(const string& title, const string& speaker,
    const string& keywords, const string& audio,
    const string& videoFile)
        : title(title), speaker(speaker), keywords(keywords),
           audio(audio), videoFile(videoFile)
    {}

const string& Talk::getTitle() const {
    return title;
}

const string& Talk::getSpeaker() const{
    return speaker;
}

const string& Talk::getKeywords() const{
    return keywords;
}

const string& Talk::getAudio() const {
    return audio;
}

const string& Talk::getVideoFile() const {
    return videoFile;
}

// Returns true if keyword appears anywhere in the keywords string
bool Talk::contains(const string& keyword) const {
   return keywords.find(keyword) != string::npos;
}

// Prints speaker, title, and keywords to stream
void Talk::print(ostream& ost) const {
    ost << "Speaker: " << speaker << endl;
    ost << "Title: " << title << endl;
    ost << "Keywords: " << keywords << endl;
}

// Delegates to print()
ostream& operator<<(ostream& ost, const Talk& t) {
    t.print(ost);
    return ost;
}