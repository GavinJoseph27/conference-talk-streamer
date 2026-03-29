#ifndef CONFERENCE_H
#define CONFERENCE_H

#include <iostream>
#include <string>
#include "Talk.h"
#include "List.h"

using namespace std;

// Stores conference metadata and its collection of Talks
class Conference {
    friend ostream& operator<<(ostream& ost, const Conference& c); // calls print()
    
    public:
        //constructor
        Conference(const string& name, const string& description);
        
        //destructor
        ~Conference();

        bool operator==(const string& rhs) const; // compares conference name to string

        Talk* getTalk(int index) const; // returns Talk at index, exits if out of bounds
        int getSize() const; // returns number of Talks
        const string& getName() const; // returns conference name

        void print(ostream&) const; // prints name and description
        void printWithTalks(ostream&) const; // prints name, description, and all Talks

        void add(Talk*); // adds Talk to collection
    private:
        List<Talk*> talks; // collection of Talks
        string name, description;
};

#endif