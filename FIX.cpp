//
//  FIX.cpp
//  
//
//  Created by Joseph Canero on 3/10/14.
//  This is the implementation file for the FIX class. It handles all of the necessary operations concerning Financian Information eXchange
//  objects.
//  This class has functionality to create, parse, output, and retrieve information regarding FIX messages.

#include "FIX.h"

// constructor method. accepts input FIX string as parameter. will then parse the string and create a map
FIX::FIX(string str) {
    // assign the input FIX string
    inputMsg = str;
    parse();
}

// parse method.
void FIX::parse() {
    
    // this segment will tokenize the string by | delimiter
    // create a pointer the size of the input msg
    char * cstr = new char [inputMsg.length()+1];
    std::strcpy (cstr, inputMsg.c_str());
    
    // cstr now contains a c-string copy of str
    // create pointer to a string that will hold each tokenized segment
    char * p = std::strtok (cstr,"|");
    while (p!=0)
    {
        // this value will be the key for the map
        int key = atoi(p);
        
        // find the part of the string where the '=' character is
        // the loop assumes well-made FIX strings that have an = character in each substring
        int pos = 0;
        bool f = true;
        while (f) {
            if (p[pos] == '=') {
                f = false; // break out of the loop
            }
            pos++;
        }
        
        // create the substring that will be used as the value for the map
        string val = "";
        while (p[pos] != '\0') {
            val += p[pos];
            pos++;
        }
        
        // now the key and value pair are created. insert them into the map
        msgContents.insert(pair<int, string>(key, val));
        
        // continue parsing
        p = strtok(NULL,"|");
    }
    delete[] cstr;
    
}

// this method will output the contents of the map into a neat fashion.
void FIX::outputMap() {
    // return an iterator of the map, loop through, and output each pair
    for (map<int, string>::iterator iter = msgContents.begin(); iter != msgContents.end(); iter++) {
        cout << iter->first << " => " << iter->second << endl;
    }
}

// this accessor method will either return the contents of the value associated with the desired key, or it will return a string saying the
// key-value pair does not exist
string FIX::retrieve(int key) {
    string result = ""; // output string
    
    // create iterator and try and find the desired key-value pair
    map<int, string>::iterator iter = msgContents.find(key);
    
    // if there is no desired element, create the error message, else create a string with the contents.
    if(iter == msgContents.end()) result = "There is no tag associated with that element!";
    else result = iter->second;
    
    // return result
    return result;
}
