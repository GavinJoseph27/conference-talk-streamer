#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include <fstream>
#include "Talk.h"

using namespace std;

// Abstract base class for all search types
class Search {

    public:
        virtual ~Search() {} // virtual destructor for safe polymorphic deletion
        virtual bool matches(const Talk*) = 0; // returns true if Talk matches search criteria
        virtual void print(ostream& ost) = 0; // prints search description to stream
        
};

// Matches Talks by speaker name
class S_Search : public virtual Search {
    public:
        S_Search(const string& speaker);
        virtual bool matches(const Talk*);
        virtual void print(ostream& ost);
    private:
        string speaker;
};

// Matches Talks by keyword
class K_Search : public virtual Search {
    public:
        K_Search(const string& keyword);
        virtual bool matches(const Talk*);
        virtual void print(ostream& ost);
    private:
        string keyword;
};

// Matches Talks by speaker OR keyword (diamond inheritance)
class SK_Search : public S_Search, public K_Search {
    public:
        SK_Search(const string& speaker, const string& keyword);
        virtual bool matches(const Talk*);
        virtual void print(ostream& ost);
};

#endif