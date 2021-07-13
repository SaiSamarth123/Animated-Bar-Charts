/**
 * @file: tests.cpp
 *
 * @description: Program contains the test functions used to test bar.h, barchart.h and barchartanimate.h
 *
 * Code Written by
 * @author: Sai Samarth Patipati Umesh
 * U. of Illinois, Chicago
 * @date: 2/21/21
 *
 */
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "barchartanimate.h"
using namespace std;
// testBarDefaultConstructor: tests the default values of Bar constructed using default constructor
bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;  // tests the getName function
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;  // tests the getValue function
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;  // tests the getCategory function
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}
// testBarParamConstructor: checks the value, name and category of Bar constructed using parameter constructor.
bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;  // tests the getName function
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;  // tests the getValue function
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;  // tests the getCategory function
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    cout << "testBarGetName: all passed!" << endl;
    cout << "testBarGetValue: all passed!" << endl;
    cout << "testBarGetCategory: all passed!" << endl;
    return true;
}
// testOperator1: tests the operator< function of the Bar class
bool testOperator1() {
    Bar b1("Chicago", 210093, "North America");
    Bar b2("Sydney", 10000, "Australia");
    if (b2 < b1) {
        cout << "testOperator1: < operator passed!" << endl;
        return true;
    }
    cout <<"testOperator1: < operator failed!" << endl;
    return false;
}
// testOperator2: tests the operator<= function of the Bar class
bool testOperator2() {
    Bar b1("Chicago", 210093, "North America");  // creates 3 bars to check
    Bar b2("Sydney", 10000, "Australia");
    Bar b3("Delhi", 210093, "Asia");
    if (b2 <=b1 && b3<=b1) {  // b1 is greater than b2 and equal to b3
        cout << "testOperator2: <= operator passed!" << endl;
        return true;
    }
    cout <<"testOperator2: <= operator failed!" << endl;
    return false;
}
// testOperator3: tests the operator> function of the Bar class
bool testOperator3() {
    Bar b1("Chicago", 210093, "North America");  // create 2 bars to check
    Bar b2("Sydney", 10000, "Australia");
    if (b1 > b2) {  // b1 is greater than b2 in this case
        cout << "testOperator3: > operator passed!" << endl;
        return true;
    }
    cout <<"testOperator3: > operator failed!" << endl;
    return false;
}
// testOperator4: tests the operator>= function of the Bar class
bool testOperator4() {
    Bar b1("Chicago", 210093, "North America");  // create 3 bars to check
    Bar b2("Sydney", 10000, "Australia");
    Bar b3("Delhi", 210093, "Asia");
    if (b1 >=b2 && b1>=b3) {  // b1 is greater than b2 and equal to b3
        cout << "testOperator4: >= operator passed!" << endl;
        return true;
    }
    cout <<"testOperator4: >= operator failed!" << endl;
    return false;
}
// testOperators: tests the operators in the Bar class.
bool testOperators() {
    Bar b1("Los Angeles", 271000000, "North America");  // creates two bar objects to check all operators
    Bar b2("Beijing", 396700000 , "Asia");
    bool b = false;
    if (b1<b2) {
        cout << "b1 is < b2" << endl;
        b = false;
    } else if (b1<=b2) {
        cout << "b1 is <= b2" << endl;
        b = false;
    } else if (b1 > b2) {  // in this case b1 is greater
        cout << "b1 is > b2" << endl;
        b = true;
    } else if (b1 >= b2) {
        cout << "b1 >= b2" << endl;
        b = false;
    }
    return b;
}
// testBarChartDefaultConstructor: tests the default values of BarChart constructed using default constructor.
bool testBarChartDefaultConstructor() {
	BarChart b;
    if (b.getSize() != 0) {
    	cout << "testBarChartDefaultConstructor: getSize failed" << endl;  // testing if size is 0
    	return false;
    } else if (b.getFrame() != "") {
    	cout << "testBarChartDefaultConstructor: getFrame failed" << endl;  // testing is frame is empty
    	return false;
    }
    cout << "testBarChartDefaultConstructor: all passed!" << endl;
    return true;
}
// testBarChartParamConstructor: tests the size and frame of Barchart constructed using the parameter constructor.
bool testBarChartParamConstructor() {
	BarChart b(100000);
	BarChart b1(12345);
    if (b.getSize() != 0 || b1.getSize() != 0) {
    	cout << "testBarChartParamConstructor: getSize failed" << endl;  // testing if size is 0
    	return false;
    } else if (b.getFrame() != "" || b1.getFrame() != "") {
    	cout << "testBarChartParamConstructor: getFrame failed" << endl;  // testing if frame is empty
    	return false;
    }
    cout << "testBarChartParamConstructor: all passed!" << endl;
    return true;
}

bool testBarChartCopyConstructor() {
    BarChart bc(10);
    BarChart bcCopy(bc);
    if (bc.getSize() != bcCopy.getSize()) {  // checks to see if they have same size
        cout << "testBarChartCopyOperator: getSize failed" << endl;
        return false;
    } else if (bc.getFrame() != bcCopy.getFrame()) {  // checks to see if they have same frame
        cout << "testBarChartCopyOperator: getFrame failed" << endl;
        return false;
    }
    cout << "testBarChartCopyConstructor: all passed!" << endl;
    return true;
}
// testBarChartCopyOperator: tests the copy operator of the BarChart class
bool testBarChartCopyOperator() {
    BarChart b1(20);
    BarChart b2 = b1;
    if (b2.getSize() != b1.getSize()) {  // checks to see if they have same size
        cout << "testBarChartCopyOperator: getSize failed" << endl;
        return false;
    } else if (b2.getFrame() != b2.getFrame()) {  // checks to see if they have same frame
        cout << "testBarChartCopyOperator: getFrame failed" << endl;
        return false;
    }
    cout << "testBarChartCopyOperator: all passed!" << endl;
    return true;
    
}
// testBarChartClear: tests the clear function of the BarChart class
bool testBarChartClear() {
    BarChart b(20);
    BarChart b1;
    b.clear();
    b1.clear();
    if (b.getSize() != 0 || b1.getSize() != 0) {  // checks if the size is cleared
        cout << "testBarChartClear: getSize failed" << endl;
        return false;
    } else if (b.getFrame() != "" || b1.getFrame() != "") {  // checks if the frame has default value
        cout << "testBarChartClear: getFrame failed" << endl;
        return false;
    }
    cout << "testBarChartGetSize: all passed" << endl;
    cout << "testBarChartClear: all passed!" << endl;
    return true;
}
// testBarChartSetFrame: tests the set frame function of BarChart class
bool testBarChartSetFrame() {
    BarChart b;
    BarChart b1(20);
    b.setFrame("Red");
    b1.setFrame("Green");
    if (b.getFrame() != "Red" || b1.getFrame() != "Green") {  // comparing getframe to added strings
         cout << "testBarChartSetFrame: setFrame failed" << endl;
         return false;
    }
    cout << "testBarChartGetFrame: all passed!" << endl;
    cout << "testBarChartSetFrame: all passed!" << endl;
    return true;
}
// testBarChartAddBar: tests the add bar function of the BarChart class
bool testBarChartAddBar() {
    // adds two bars and checks if the right details were initialised
    BarChart b(20);
    b.addBar("Chicago", 1000000, "US");
    b.addBar("Tokyo", 45665, "Japan");
    if(b[0].getName() != "Chicago" || b[1].getName() != "Tokyo") {  // checks the names of Bars
        cout << "testBarChartAddBar: getName failed!" << endl; 
        return false;
    } else if (b[0].getCategory() != "US" || b[1].getCategory() != "Japan") {  // checks the categories
        cout << "testsBarChartAddBar: getCategory failed!" << endl;
        return false;
    } else if (b[0].getValue() != 1000000 || b[1].getValue() != 45665) {  // checks the values
        cout << "testBarChartAddBar: getValue failed" << endl;
        return false;
    }
    cout << "testBarChartAddBar: all passed!" << endl;
    return true;
}
// testBarChartOperator: tests the operator function of the BarChart class.
bool testBarChartOperator() {
    // creates two barchart objects and compares the contents using operator
    BarChart b(10);
    b.addBar("Chicago", 1000000, "US");
    b.addBar("Tokyo", 45665, "Japan");
    if(b[0].getName() != "Chicago" || b[1].getName() != "Tokyo") {  // checks the names
        cout << "testBarChartOperator[]: getName failed!" << endl; 
        return false;
    } else if (b[0].getCategory() != "US" || b[1].getCategory() != "Japan") {  // checks the category
        cout << "testsBarChartOperator[]: getCategory failed!" << endl;
        return false;
    } else if (b[0].getValue() != 1000000 || b[1].getValue() != 45665) {  // checks the values
        cout << "testBarChartOperator[]: getValue failed" << endl;
        return false;
    }
    cout << "testBarChartOperator: all passed!" << endl;
    return true;
}
// testBarChartDump: tests the dump function of the BarChart class
bool testBarChartDump() {
    BarChart bc(3);
    bc.setFrame("1950");
    bc.addBar("Chicago", 1020, "US");
    bc.addBar("NYC", 1300, "US");
    bc.addBar("Paris", 1200, "France");
    // using stringstream to get output
    stringstream ss("");
    bc.dump(ss);
    // creating the answer using the dump format
    string ans = "frame: 1950\n";
    ans+= "NYC 1300 US\n";
    ans+= "Paris 1200 France\n";
    ans+= "Chicago 1020 US\n";
    cout << ans;
    if ( ss.str() != ans) {  // comparing the two strings to see if the match
        cout << "testBarChartDump: Function failed!" << endl;
        return false;
    }
    cout << "testBarChartDump: all passed!" << endl;
    return true;
}
// testBarChartGraph: tests the graph function of the BarChart class 
bool testBarChartGraph() {
    // graphs three bars and to check if the function outputs with the right colors
    string RED("\033[1;36m");
    string BLUE("\033[1;33m");
    BarChart bc(3);
    bc.setFrame("1950");
    bc.addBar("Chicago", 1020, "US");
    bc.addBar("NYC", 1300, "US");
    bc.addBar("Paris", 1200, "France");
    map<string, string> colorMap;
    colorMap["US"] = RED;
    colorMap["France"] = BLUE;
    bc.graph(cout, colorMap, 3);  // visually test if the colors match
    return true;
}
// testBarChartAnimateConstructor: tests the constructor of the BarChartAnimate class
bool testBarChartAnimateConstructor() {
    // testing one object
    BarChartAnimate bca("Cities", "Population(in thousands)", "Source");
    if (bca.getSize() != 0) {  // checking the size
    	cout << "testBarChartAnimateConstructor: getSize failed" << endl;
    	return false;
    }
    // testing the second object
    BarChartAnimate bca1("Shows", "Viewers(in thousands)", "Source");
    if (bca1.getSize() != 0) {  // checking the size
    	cout << "testBarChartAnimateConstructor: getSize failed" << endl;
    	return false;
    }
    cout << "testBarChartAnimateConstructor: all passed!" << endl;
    return true;
    
}
// testBarChartAnimateAddFrame: tests the add frame function of the BarChartAnimate class
bool testBarChartAnimateAddFrame() {
    ifstream infile("cities.txt");
    string title, xLabel, source;
    // getting the required information from file to create object
    getline(infile, title);
    getline(infile, xLabel);
    getline(infile, source);
    BarChartAnimate bc(title, xLabel, source);  // create the object
    while (!infile.good()) {
        return false;
    }
    while(!infile.eof() && !infile.fail()) {  // run until the end of the file
        bc.addFrame(infile);
    }
    if (bc.getSize() != 519) {  // checks if 519 Barcharts were added
        cout << "testBarChartAnimateAddFrame: getSize for BarChartAnimate failed" << endl;
    	return false;
    } else {
        for (int i = 0; i < 519; i++) {  // looping through all the barcharts in array
            if (bc[i].getSize() != 12) { // also testing the operator function and number of bars
                cout << "testBarChartAnimateAddFrame: getSize for BarChart failed" << endl;
                return false;
            }
        }
    }
    cout << "testBarChartAnimateGetSize: all passed!" << endl;
    cout << "testBarChartAnimateAddFrame: all passed!" << endl;
    return true;
}
// testBarChartAnimate: tests the animate function of the BarChart class.
bool testBarChartAnimate() {
    ifstream infile("cities.txt");
    string title, xLabel, source;
    // getitng the required information to create an object
    getline(infile, title);
    getline(infile, xLabel);
    getline(infile, source);
    BarChartAnimate bca(title, xLabel, source);  // create the object
    while (!infile.good()) {
        return false;
    }
    while(!infile.eof() && !infile.fail()) {  // run till the end of the file is reached
        bca.addFrame(infile);
    }
    int k = 1500;  // initial frame from cities.txt is 1500
    for (int i = 0; i < bca.getSize(); i++) { // testing get size
        if (stoi(bca[i].getFrame()) != k) { // testing operator and get frame again using stoi
            cout << "testBarChartAnimateOperator: operator failed!" << endl;
        }
        k++;  // incrementing the frame
    }
    cout << "testBarChartAnimateOperator: all passed!" << endl;
    bca.animate(cout, 12, -1);
    cout << "testBarChartAnimate: all passed!" << endl;
    return true;
}
int main() {
	testBarDefaultConstructor();  // to test default constructor of bar.h
	testBarParamConstructor();  // to test parameter constructor of bar.h
	testOperator1();  // to test the < operator of bar.h
	testOperator2();  // to test the <= operator of bar.h
	testOperator3();  // to test the > operator of bar.h
	testOperator4();  // to test the >= operator of bar.h
	testOperators();  // to test all the operators of bar.h
	testBarChartDefaultConstructor();  // to test the default constructor of barchart.h
	testBarChartParamConstructor();  // to test the parameter constructor of barchart.h
	testBarChartCopyConstructor();  // to test the copy constructor of barchart.h
	testBarChartCopyOperator();  // to test the copy operator of barchart.h
	testBarChartClear();  // to test the clear function of barchart.h
	testBarChartSetFrame();  // to test the setframe function of barchart.h
	testBarChartAddBar();  // to test the addbar function of barchart.h
	testBarChartOperator();  // to test the operator function of barchart.h
	testBarChartDump();  // to test the dump function of barchart.h
	testBarChartGraph();  // to test the graph function of barchart.h. Have to test visually
	testBarChartAnimateConstructor();  // to test the constructor of barchartanimate.h
	testBarChartAnimateAddFrame();  // to test the add frame function of barchartanimate.h
	testBarChartAnimate();  // to test the animate function of barchart.h. Have to test visually
    return 0;
}