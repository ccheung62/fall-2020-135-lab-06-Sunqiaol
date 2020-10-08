#include <iostream>
#include "funcs.h"

using namespace std;
// add functions here

void test_ascii(string s){
    int x = 0;
    int y = s.size();
    for(int i = 0;i<y;i++){ // loop through the string
        cout<<s[i]<< " "<<int(s[i])<<endl; // print out with ascii
    }
}
