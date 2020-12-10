#include<iostream>
#include"caesar.h"

using namespace std;
char shiftChar(char c, int rshift){
    char news = ' ';
    if (rshift%26 < 0){
      rshift = 26+(rshift%26);
    }
    else{
      rshift = rshift%26;
    }
    int place = int(c) + (rshift%26);
    int x =0;
    if(isupper(c)){ //check for upper
        if(place >90){
	  x = place - 90; 
            news = char(64 + x);
            return news;
        }
        else if (place < 65){
	  x = 65 - place;
	  news = char(90 - x);
	  return news;
	}
	else 
        {
            news= char(place);
            return news;
        }
    }
    else if(islower(c)){ // check for lower
        if(place > 122){
	  x = place - 122;
            news = char(96+x);
            return news;
        }
        else if (place < 97){
	  x = 97 - place;
	  news = char(122 - x);
	  return news;
	}
	else 
	{
            news = char(place);
            return news;
        }	
    }
    return c;
}

std::string encryptCaesar(std::string plaintext,int rshift){
    std::string result="";
    for(int i =0;i<plaintext.size();i++){
      result += shiftChar(plaintext[i],rshift);
    }
    return result;
}
