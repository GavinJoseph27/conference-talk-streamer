#include <iostream>
#include <string>
#include "SummitStream.h"

// Deletes all owned Conference objects
SummitStream::~SummitStream() {
    for (int i = 0; i < conferences.getSize(); i++) {
        delete conferences[i];
    }
}

// Adds Conference to collection
void SummitStream::addConference(Conference* confer){
    conferences += confer;
}

// Finds Conference by name and adds Talk to it, returns false if not found
bool SummitStream::addTalk(Talk* talk, const string& conferenceName){
    for (int i = 0; i < conferences.getSize(); i++){
        if (*conferences[i] == conferenceName){
            conferences[i]->add(talk);
            return true;
        }
    }
    cerr << "Error: conference " << conferenceName << " not found" << endl;
    return false;
}

// Returns const reference to all Conferences
const List<Conference*>& SummitStream::getConferences() const{
    return conferences;
}

// Returns Conference at given index
Conference* SummitStream::getConference(int index) const{
    return conferences[index];
}

// Returns Conference by name, exits if not found
Conference* SummitStream::getConference(const string& name) const{
    for (int i = 0; i < conferences.getSize(); i++){
        if (*conferences[i] == name){   
            return conferences[i];
        }
    }
    cerr << "Error: conference " << name << " not found" << endl;
    exit(1);
}

// Searches all Talks across all Conferences, adds matches to output list
void SummitStream::getTalks(Search& search, List<Talk*>& talks) const{
    for (int i = 0; i < conferences.getSize(); i++){
        for (int j = 0; j < conferences[i]->getSize(); j++) {
            Talk* talk =  conferences[i]->getTalk(j);
            if (search.matches(talk)){
                talks += talk;
            }
        }
    }
}
