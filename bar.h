/**
 * @file: bar.h
 *
 * @description: Program contains the value and category of the given item
 *
 * Code Written by
 * @author: Sai Samarth Patipati Umesh
 * U. of Illinois, Chicago
 * @date: 2/21/21
 *
 */
#include <iostream>
#include <string>
#include "myrandom.h"
using namespace std;

//
// Bar
//
class Bar {
 private:
    // Private member variables for a Bar object
    string n; // to hold the name.
    int val; // to hold the value.
    string cat; // to hold the category.

 public:
    // default constructor:
    Bar() {
        n = "";
        val =  0;
        cat = "";
    }
    //
    // a second constructor:
    //
    // Parameter passed in constructor Bar object.
    //
    Bar(string name, int value, string category) {
        this -> n = name; //assigning this variables to the given parameters.
        this -> val = value;
        this -> cat = category;
    }
    // destructor:
    virtual ~Bar() {
    }
    // getName:
	string getName() {
        return n; // return name.
	}
    // getValue:
	int getValue() {
        return val; // return the value.
	}
    // getCategory:
	string getCategory() {
        return cat; // return the category.
	}
	// operator<: checks if the given Bar is greater than this bar
	bool operator<(const Bar &other) const {
	    if (this -> val < other.val) {  // compares the values of two bars
	        return true;
	    }
        return false;
	}
	// operator<=: checks if the given Bar is greater than or equal to this bar.
	bool operator<=(const Bar &other) const {
	    if (this -> val <= other.val) {  // compares the values of two bars
	        return true;
	    }
        return false;
	}
	// operator>: checks if the given Bar is less than this bar.
	bool operator>(const Bar &other) const {
	    if (this -> val > other.val) {  // compares the values of two bars
	        return true;
	    }
        return false;
	}
	// operator>=: checks if the current bar is less than or equal to this bar.
	bool operator>=(const Bar &other) const {
	    if (this -> val >= other.val) {  // compares the values of two bars
	        return true;
	    }
        return false;
	}
};