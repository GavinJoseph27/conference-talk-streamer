#include <iostream>
#include <string>
#include "Conference.h"

using namespace std;

Conference::Conference(const string& name, const string& description)
    : name(name), description(description) {}

// Deletes all owned Talk objects
Conference::~Conference() {
    for (int i = 0; i < talks.getSize(); i++) {
        delete talks[i];
    }
}

// Returns true if conference name matches given string
bool Conference::operator==(const string& rhs) const{
    return name == rhs;
}

// Returns Talk at index, exits if out of bounds
Talk* Conference::getTalk(int index) const{
    if (index < 0 || index >= talks.getSize()){
        cerr<<"List index out of bounds"<<endl;
		exit(1);
    }
    return talks[index];
}

// Returns number of Talks in this Conference
int Conference::getSize() const{
    return talks.getSize();
}

const string& Conference::getName() const{
    return name;
}

// Prints name and description
void Conference::print(ostream& ost) const{
    ost << "Name: " << name << "Desciption: " << description << endl;
}

// Prints name, description, and all Talks
void Conference::printWithTalks(ostream& ost) const{
    ost << "Name: " << name << "Desciption: " << description << 
    "Talks: " << endl;
    for (int i = 0; i < talks.getSize(); i++){
        ost << *talks[i] << endl;
    } 
}

// Adds Talk pointer to the collection
void Conference::add(Talk* talk){
    talks += talk;
}

// Delegates to print()
ostream& operator<<(ostream& ost, const Conference& c) {
    c.print(ost);
    return ost;
}