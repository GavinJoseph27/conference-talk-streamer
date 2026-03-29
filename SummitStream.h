#ifndef SUMMITSTREAM_H
#define SUMMITSTREAM_H

#include <iostream>
#include <string>
#include "Conference.h"
#include "Search.h"
#include "List.h"
#include "Talk.h"

// Central store for all Conferences and their Talks
class SummitStream {
    public:
        ~SummitStream(); // deletes all owned Conference objects
        void addConference(Conference* confer); // adds Conference to collection
        bool addTalk(Talk* talk, const string& conferenceName); // adds Talk to named Conference, returns false if not found
        const List<Conference*>& getConferences() const; // returns all Conferences
        Conference* getConference(int index) const; // returns Conference at index
        Conference* getConference(const string& name) const; // returns Conference by name, exits if not found
        void getTalks(Search& search, List<Talk*>& talks) const; // finds all Talks matching search, adds to output list

    private:
        List<Conference*> conferences; // owned collection of Conferences
};

#endif