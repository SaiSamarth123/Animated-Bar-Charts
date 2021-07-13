/**
 * @file: barchartanimate.h
 *
 * @description: Program prints different frames(barcharts) and animates them. 
 *
 * Code Written by
 * @author: Sai Samarth Patipati Umesh
 * U. of Illinois, Chicago
 * @date: 2/21/21
 *
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used in autograder, do not remove
#include "barchart.h"
using namespace std;
//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // C style BarChart array
    int size, count;  // size for number of elements in array and count for number of colors.
    int capacity;  // int to hold the capacity of the array
    string Title;  // string to hold the title.
    string xLabel;  // string to hold xLabel
    string Source;  // string to hold source
    map<string, string> colorMap;  // map for colors and categories.
    // addColors: Helper function that fills the colorMap with colors using categories that are passed from the fillBarChart funtion.
    void addColors(string category, map<string, string>& colorMap) {
      //  unsigned int j = 0;
    	bool present;
    	if (!colorMap.empty()) {  // if the colorMap is not empty check for categories.
    	    present = false;
    	    if (count < 7) {  // loops till all the colors are used.
    	        for (auto e: colorMap) {
    	            if (e.first == category) { // check if the category is present in the map already
    	                present = true;  // means the category is already in colorMap.
    	                break;
    	            }
    	        }
    	        if (!present) {
    	            colorMap[category] = COLORS.at(count); // only adds to map if it's not present.
    	            count++;  // increments color count
    	        }
    	    } else {  // if the color count reaches 7, loop back to 0
    	        count = 0; // reset to the first color if there are more than 7 items.
    	        for (auto e: colorMap) {  // check category and elem.first
    	            if (e.first == category) { // checks if the category is in the map.
    	                present = true;
    	                break;
    	            }
    	        }
    	        if(!present) {  // adds to the map if the category is not present
    	            colorMap[category] = COLORS.at(count); // only add if not present.
    	            count++;  // increments color count
    	        }
    	    }
    	} else {
    	    count = 0;  // if the colorMap is empty add the first color.
    	    colorMap[category] = COLORS.at(count);
    	    count++;
    }
    }
    // fillBarChart: Creates new bars and adds them to BarChart array. It uses an iftream to get the content. This is a helper function for addFrame
    void fillBarChart(string s, BarChart& b, ifstream &file) {
        string frame, name, country, value, category, waste;
        int counter = 0;
        int val;
      //  bool isTrue = false;
        while (counter < stoi(s)) { // loops till all the end of one frame
        // getting the required details from file.
    	  getline(file, frame, ',');
    	  b.setFrame(frame);
    	  getline(file, name, ',');
    	  getline(file, country, ',');
    	  getline(file, value, ',');
    	  val = stoi(value);
    	  getline(file, category);
    	  addColors(category, colorMap);  // calls the function to fill colorMap.
    	  bool t = b.addBar(name, val, category);  // adding a new bar to barchart.
    	  if (t) {
    	      counter++;  // incrementing the counter if the bar was added successfully.
    	      }
        }
    }
 public:
    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        barcharts = new BarChart[4];
        Title = title;
        xLabel = xlabel;
        Source = source;
        capacity = 4;
        size = 0;
        count = 0;
    }
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        if (capacity > 0) {
            delete [] barcharts;
        }
    }
    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
    	string frame, name, country, value, category, waste, s;
    	getline(file, waste);  // first line is blank
    	getline(file, s);  // second line contains the size of barchart
        if (s != "") {
    	BarChart b(stoi(s));  // create new BarChart of size s.
    	fillBarChart(s, b, file);  // fill the BarChart with bars using file
    	if (size == capacity) {  // grow the array if it is full.
    	        int newCapacity = capacity * 2;
    	        BarChart* bar = new BarChart[newCapacity];
    	        // copy the elements from A to the new array:
    	        for (int i = 0; i < size; ++i) {
    	            bar[i] = barcharts[i];
    	        }
    	        if (capacity != 0) {
    	            delete [] barcharts;  // delete the contents of barchart
    	        }
    	        barcharts = new BarChart[newCapacity];
    	        for (int i = 0; i < size; ++i) {
    	            barcharts[i] = bar[i];
    	        }
                capacity = newCapacity;
                delete[] bar;  // deleting the temp BarChart array
    	        }
    	barcharts[size] = b;
    	size++;
        }
    }
    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
        int end = 0;
        if (endIter == -1) {
            end = size;
        } else {
            end = endIter;
        }
        for (int i = 0; i < end; i++) {
            usleep(3 * microsecond);
            output << CLEARCONSOLE;  // clearing the console after every frame.
            output << BLACK << Title << endl;  // outputs the title with BLACK color.
            output << BLACK << Source << endl;  // outputs the source with BLACK color.
            barcharts[i].graph(output, colorMap, top);  // calls the graph function 
            output << BLACK << xLabel << endl;
            output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
        }
	}
    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize() {
        return size;  // return size.
    }
    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i) {
       if (i < 0 || i >= size) {  // throw out of bounds error if i is out of bounds.
            throw out_of_range("BarChart: i out of bounds");
        }
        return barcharts[i];
    }
};
