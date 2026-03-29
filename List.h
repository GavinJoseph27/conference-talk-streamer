#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

// Templated fixed-size dynamic array container
template <class T>
class List {
	public:
		//constructor
		List(); 
				
		//destructor
		~List(); 
		
		List<T>& operator+=(const T&); // adds element to end of list
		List<T>& operator-=(const T&); // removes first matching element
		const T& operator[](int index) const; // read-only indexed access
		T& operator[](int index); // read-write indexed access
        void clear(); // resets list to empty

		int getSize() const; // returns number of elements
		bool isFull() const; // returns true if list is at capacity
	
	
	private:
		int numElements; // current number of elements
		T* elements; // underlying array
	
};

// allocates array of MAX_ARRAY elements
template <class T>
List<T>::List(){
	elements = new T[MAX_ARRAY];
	numElements = 0;
}

// frees allocated array
template <class T>
List<T>::~List(){
	delete [] elements;
}

// Adds element if not full, silently ignores if full
template <class T>
List<T>& List<T>::operator+=(const T& s){
	if (numElements >= MAX_ARRAY)   return *this;
  	elements[numElements++] = s;
	return *this;
}

// Finds and removes first match, shifts remaining elements left
template <class T>
List<T>& List<T>::operator-=(const T& s){
	int index = 0;
	while (index < numElements){
		if (s == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
	return *this;
}

template <class T>
int List<T>::getSize() const{
	return numElements;
}

template <class T>
bool List<T>::isFull() const {
	return numElements >= MAX_ARRAY;
}

// Exits program if index is out of bounds
template <class T>
const T& List<T>::operator[](int index) const{
	if (index < 0 || index >= numElements) {
		cerr<<"List index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
T& List<T>::operator[](int index) {
	if (index < 0 || index >= numElements) {
        cerr << "List index out of bounds" << endl;
        exit(1);
    }
    return elements[index];
}

// Resets size to 0 without freeing memory
template <class T>
void List<T>::clear() {
    numElements = 0;
}


#endif