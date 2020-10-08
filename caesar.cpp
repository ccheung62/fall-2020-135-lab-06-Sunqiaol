#include<iostream>
#include"caesar.h"

using namespace std;
char shiftChar(char c, int rshift){
    char news =' ';
    int place = int(c) + rshift;
    int x =0;
    if(isupper(c)){ //check for upper
        if( place >90){
            x = place - 91;
            news = char(65 + x);
            return news;
        }
        else
        {
            news= char(int(place));
            return news;
        }
        
    }
    else if(islower(c)){ // check for lower
        if(place >122){
            x = place -123;
            news = char(97+x);
            return news;
        }
        else{
            news = char(int(place));
            return news;
        }
    }
    else{
        return c;
    }
}

std::string encryptCaesar(std::string plaintext,int rshift){
    std::string result="";
    for(int i =0;i<plaintext.size();i++){
        if(isalpha(plaintext[i])){
            result += shiftChar(plaintext[i],rshift);
        }
        else{
            result += plaintext[i];
        }
    }
    return result;
}