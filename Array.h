
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {
	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(T);
		int getSize() const;
		bool isFull() const;

		T operator[](int) const;

	private:
		int size;
		T elements[MAX_ARR];
	
};

template <class T>
Array<T>::Array(): size(0) {}

template <class T>
Array<T>::~Array(){}

template <class T>
void Array<T>::add(T t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template <class T>
int Array<T>::getSize() const {
	return size;
}

template <class T>
bool Array<T>::isFull() const {
	return size >= MAX_ARR;
}

template <class T>
T Array<T>::operator[](int index) const {
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
ostream& operator<<(ostream& out, const Array<T>& array) {
	for (int i = 0; i < array.getSize(); ++i) {
		out << *array[i] << "\n";
	}
	return out;
}
#endif