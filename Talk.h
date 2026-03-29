#ifndef TALK_H
#define TALK_H

#include <iostream>
#include <string>

using namespace std;

// Stores talk metadata and content
class Talk {
    friend ostream& operator<<(ostream& ost, const Talk& t); // calls print()
    public:
        Talk(const string& title, const string& speaker,
            const string& keywords, const string& audio,
            const string& videoFile);
        
        const string& getTitle() const;
        const string& getSpeaker() const;
        const string& getKeywords() const;
        const string& getAudio() const;
        const string& getVideoFile() const;

        bool contains(const string& keyword) const; // returns true if keyword appears in keywords string
        void print(ostream&) const; // prints speaker, title, and keywords
    private:
        string title, speaker, keywords, audio, videoFile;
};

#endif