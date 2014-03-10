//
//  FIX.h
//  
//
//  Created by Joseph Canero on 3/10/14.
//  This is the header file for the FIX class. It contains all of the requisite declarations for the implementation file.
//

#ifndef ____FIX__
#define ____FIX__

#include <iostream>
#include <map>
#include <string>

using namespace std;

class FIX {
    map<int, string> msgContents;   // this map object will support associativity b/w key-value pairs that correspond to tags and content
    string inputMsg;                // this string will store the FIX message that was passed as input
    
public:
    FIX(string str);                // constructor method. accepts a string, calls the parse method to create the map of the message
    void parse();                   // parse method. this processes the FIX message and create the map corresponding to the tags
    void outputMap();               // this will output the map of the FIX message showing the corresponding tag-content pairs
    string retrieve(int);           // accessor method. this method accepts an integer parameter that indicates which tag will be retrieved
};

#endif /* defined(____FIX__) */
