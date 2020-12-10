#include<iostream>
#include"caesar.h"
#include"decrypt.h"
/*
char Reverse(char c, int rshift){
    char news =' ';
    int place = int(c) - rshift;
    int x =0;
    if(isupper(c)){ // check if it upper case
        if(place <65){
          x = 65 - place; 
          news = char(91-x);
          return news; 
        }
        else{
            news = char(place);
            return news;
        }
        
    }
    else if(islower(c)){ // check if lower case
       if(place <97){
           x = 97 - place;
           news = char(123-x);
           return news;
       }
       else{
           news = char(place);
           return news;
       }
    }
    else{ // either so return it self
        return c;
    }
}
*/


std::string decryptCaesar(std::string ciphertext,int rshift){
    std::string plain="";
    for(int i =0;i<ciphertext.size();i++){ // loop the whole string
        if(isalpha(ciphertext[i])){
            plain += shiftChar(ciphertext[i],-rshift); // use the function to shift
        }
        else{
            plain += ciphertext[i];
        }
    }
    return plain;
}


std::string decryptVigenere(std::string ciphtertext,std::string keyword){
       std::string result;
    int x = 0;
   for(int i =0;i<ciphtertext.size();i++){ // loop through string
       if(isalpha(ciphtertext[i])){
	 result += shiftChar(ciphtertext[i],-(int(tolower(keyword[x]))-97));
        if(x>=keyword.size()-1){ // check for key word
            x=0;
        }
        else
        {
            x++;
        }
        
       }else{
           result += ciphtertext[i];
       }
   }
    return result;
}
