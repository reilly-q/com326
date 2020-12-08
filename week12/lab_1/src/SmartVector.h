#pragma once
//
//  SmartVector.h
//  A custom Smart Vector implementation based on the std::vector
//
//  Created by Effirul I Ramlan on 01/12/2019.
//  Copyright � 2019 Effirul I Ramlan. All rights reserved.
//

#ifndef SmartVector_h
#define SmartVector_h

#include <iostream>
#include <vector>
#include <random>

#include "../inc/common.hpp"

template<typename T>
class SmartVector {
private:
	std::vector<T> smartVector_;

public:
	// Constructor accepts std::vector
	SmartVector(const std::vector<T>& t) {
        smartVector_ = t;
	}

	// Constructor accepts T array and array size
	SmartVector(const T t[], int s) {
        for(int i{0}; i < s; i++) {
            smartVector_.push_back(t[i]);
        }
	}

	// Push function with T array and array size - similar to std::vector.push_back
	void Push(const T t[], int s) {
        for(int i{0}; i < s; i++) {
            smartVector_.push_back(t[i]);
        }
	}

	// Return the total sum of all elements inside the vector
	T Sum() {
        T tmp;
        for(size_t i{0}; i < smartVector_.size(); i++) {
            tmp += smartVector_.at(i);
        }

        return tmp;
	}

	// Sort the vector in ascending order
	void Sort() {
        std::sort(smartVector_.begin(), smartVector_.end());
	}

	// Random shuffle all element inside the vector - use random shuffle
	// Link: https://en.cppreference.com/w/cpp/algorithm/random_shuffle
	void Shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(smartVector_.begin(), smartVector_.end(), g);
	}

	// Return indexes for all matching elements (as std::vector) in the vector given the argument
	std::vector<int> Search(T match) {
        std::vector<int> vMatch;
        for(size_t i{0}; i < smartVector_.size(); i++) {
            if(smartVector_.at(i) == match) {

            }
        }

        return vMatch;
	}

	// Return the element of a given index - similar to std::vector.at
	T At(int i) {
        return smartVector_.at(i);
	}

	// Return the maximum size of the vector - similar to std::vector.size
	int Size() const {
        return smartVector_.size();
	}

	// Return the element of vector from index b, until index e
	SmartVector<T> Range(int b, int e) {
        auto begin = smartVector_.cbegin() + b;
        auto end = smartVector_.cbegin() + e + 1;

        std::vector<T> vR(begin, end);

        SmartVector<T> svR(vR);

        return svR;
	}

	// Erase a vector element given index
	void Erase(int index) {
        smartVector_.erase(smartVector_.begin() + index);
	}
};


#endif /* SmartVector_h */
