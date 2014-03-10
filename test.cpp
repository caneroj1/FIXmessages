//
//  test.cpp
//  
//
//  Created by Joseph Canero on 3/10/14.
//
//  This file is used to exercise the functionality of the FIX class. I hardcoded in a string representing a FIX message obtained from the
//  wikipedia page on the topic. http://en.wikipedia.org/wiki/Financial_Information_eXchange

#include "FIX.cpp"

using namespace std;
int main(void) {
    
    // input string for the object to be created
    string input = "8=FIX.4.2|9=65|35=A|49=SERVER|56=CLIENT|34=177|52=20090107-18:15:16|98=0|108=30|10=062|";

    //  create the object
    FIX msg(input);
    cout << "Outputting the map: " << endl;
    //  exercise output functionality, output the map
    msg.outputMap();
    
    //  exercise retrieval functionality, store string, output string
    cout << "Retrieving tag 52: " << endl;
    string value = msg.retrieve(52);
    cout << value << endl;
    
    return 0;
}