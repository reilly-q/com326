#pragma once
//
//  SmartVector.h
//  A custom Smart Vector implementation based on the std::vector
//
//  Created by Effirul I Ramlan on 01/12/2019.
//  Copyright © 2019 Effirul I Ramlan. All rights reserved.
//

#ifndef SmartVector_h
#define SmartVector_h

#include <iostream>
#include <vector>
#include <random>

template<typename T>
class SmartVector {
private:
	std::vector<T> smartVector_;

public:
	// Constructor accepts std::vector
	SmartVector(const std::vector<T>& t) {
	}

	// Constructor accepts T array and array size
	SmartVector(const T t[], int s) {	
	}

	// Push function with T array and array size - similar to std::vector.push_back
	void Push(const T t[], int s) {
	}

	// Return the total sum of all elements inside the vector
	T Sum() {
	}

	// Sort the vector in ascending order
	void Sort() {
	}

	// Random shuffle all element inside the vector - use random shuffle
	// Link: https://en.cppreference.com/w/cpp/algorithm/random_shuffle
	void Shuffle() {
	}

	// Return indexes for all matching elements (as std::vector) in the vector given the argument
	std::vector<int> Search(T match) {
	}

	// Return the element of a given index - similar to std::vector.at
	T At(int i) {
	}

	// Return the maximum size of the vector - similar to std::vector.size
	int Size() const {
	}

	// Return the element of vector from index b, until index e 
	SmartVector<T> Range(int b, int e) {
	}

	// Erase a vector element given index
	void Erase(int index) {
	}
};


#endif /* SmartVector_h */
