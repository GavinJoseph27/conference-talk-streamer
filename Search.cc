#include <iostream>
#include <string>
using namespace std;

#include "Search.h"

// S_Search: matches by speaker name
S_Search::S_Search(const string& speaker)
    : speaker(speaker) {}

// returns true if Talk's speaker matches
bool S_Search::matches(const Talk* talk) {
    return speaker == talk->getSpeaker();
}

void S_Search::print(ostream& ost) {
    ost << "Matches talks with speaker: " << speaker << endl;
}

// K_Search: matches by keyword
K_Search::K_Search(const string& keyword) 
    : keyword(keyword) {}

// returns true if Talk's keywords contain the keyword
bool K_Search::matches(const Talk* talk) {
    return talk->contains(keyword);
}

void K_Search::print(ostream& ost) {
    ost << "Matches talks with keyword: " << keyword << endl;
}

// SK_Search: matches by speaker OR keyword
SK_Search::SK_Search(const string& speaker, const string& keyword)
    : Search(), S_Search(speaker), K_Search(keyword) {}


// returns true if either speaker or keyword matches
bool SK_Search::matches(const Talk* talk) {
    return S_Search::matches(talk) || K_Search::matches(talk);
}

void SK_Search::print(ostream& ost) {
    S_Search::print(ost);
    K_Search::print(ost);
}