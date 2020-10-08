#include<iostream>
#include"viginere.h"
#include"caesar.h"

using namespace std;
std::string encryptVigenere(std::string plaintext,std::string keyword){
    std::string result;
    int x = 0;
   for(int i =0;i<plaintext.size();i++){
       if(isalpha(plaintext[i])){ // check if it a alpha
        result += shiftChar(plaintext[i],(int(keyword[x])-97)); // add the shift char
        if(x>=keyword.size()-1){ // loop throught the key word
            x=0;
        }
        else
        {
            x++;
        }
        
       }else{ // if not then it a space or something
           result += plaintext[i];
       }
   }
    return result;
}