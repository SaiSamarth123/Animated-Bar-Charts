/**
 * @file: barchart.h
 *
 * @description: Program contains the array of bars. Each bar represents an item or thing. The frame is defined in this class.
 *
 * Code Written by
 * @author: Sai Samarth Patipati Umesh
 * U. of Illinois, Chicago
 * @date: 2/21/21
 *
 */

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h"  // used in autograder, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, we must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;
    string frame;
 public:
    // default constructor:
    BarChart() {
        bars = nullptr;
        capacity = 0;
        size = 0;
        frame = "";
    }
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) {
        bars = new Bar[n];
        capacity = n;  // capacity is equal to the number passed in constructor.
        size = 0;  // default values for size and frame.
        frame = "";
    }
    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    BarChart(const BarChart& other) {
        this->bars = new Bar[other.capacity];  // create a new Bar array.
        for (int i = 0; i < other.size; i++) {
            // copying the contents of the array.
            this->bars[i] = other.bars[i];
        }
        // assigning the rest of the variables.
        this -> capacity = other.capacity;
        this -> size = other.size;
        this -> frame = other.frame;
    }
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    BarChart& operator=(const BarChart& other) {
        if (bars!= nullptr) {  // delete the current bars if the capacity is over 0.
            delete[] bars;
        }
        this->bars = new Bar[other.capacity];  // creating a new bar array.
        for (int i = 0; i < other.size; i++) {
            this->bars[i] = other.bars[i];  // copying the contents of the array.
        }
        // assigning the rest of the variables.
        this->size = other.size;
        this->capacity = other.capacity;
        this->frame = other.frame;
        return *this;
    }
    // clear:
    //
    // Frees memory and resets all private member variables to default
    // value.
    void clear() {
        if (bars != nullptr) {  // delete the array if it's capacity is more than 0 or if it's a nullptr.
        delete[] bars;
        }
        // reassign the variables to default.
        // bars = nullptr;
        capacity = 0;
        size = 0;
        frame = "";
    }
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() {
        if (capacity > 0 || bars == nullptr) {  // delete the array if it's size is more than 0.
            delete[] bars;
        }
    }
    // setFrame
    void setFrame(string frame) {
        this -> frame = frame;  // sets the frame of current Barchart.
    }
    // getFrame()
    // Returns the frame of the BarChart oboject.
    string getFrame() {
        return frame;  // return frame.
    }
    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
        Bar b(name, value, category);  // creating a new Bar to add to array.
        if (size == capacity) {  // if the array is full return false
            return false;
        } else {
            bars[size] = b;  // adding the new bar and increasing size.
            size = size + 1;
        }
        return true; 
    }
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
        return size;
    }
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
        // return error if i is out of bounds.
        if (i < 0 || i >= size)
        {
            throw out_of_range("BarChart: i out of bounds");  // throw the error if out of bounds.
        }
        return bars[i];
    }
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {
        sort(bars, bars + size, greater<Bar>());  // sorting the temporary array in descending order.
        output << "frame: " << frame << endl;
        // printing the content of the array in descending order.
        for (int k = 0; k < size; k++) {
            output << bars[k].getName() << " " << bars[k].getValue() << " " << bars[k].getCategory() << endl;
        }
    }
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;  // used for the length of the top bar
        string color;
        int next = lenMax;  // variable to hold the number of boxes for next bar.
        double value = 0.0;
        sort(bars, bars + size, greater<Bar>());  // sorting the array of Bars.
        for (int i = 0; i < top; i++) {  // printing the boxes of each bar in the array
            if (i < size) {
                if (colorMap.empty()) {
                    color = COLORS.at(6);
                } else {
                    color = colorMap[bars[i].getCategory()];  // getting the color using the category.
                }
                string barstr = "";  // string that holds the boxes.
                for (int j = 0; j < next; j++) {
                barstr += BOX;
                }
                output << color << barstr << " ";  // outputting the content to ostream output.
                output << bars[i].getName() << " " << bars[i].getValue() << endl;
                if (i < size -1) {
                    value = ((double)bars[1+i].getValue()/bars[0].getValue()) * lenMax;  // calculating the number of boxes for next bar using the formula.
                    next = (int)value;
                }
            }
        }
    }
};
