#include<iostream>
#include "decode.h"
#include "caesar.h"
#include <cmath>
using namespace std;


std::string automatic_decode(std::string text){
    double lowest= findfreq(text);
    int element = 0;
    std::string newtext = "";
   for(int i =1;i<=26;i++){
      newtext = encryptCaesar(text,i); // create all 26 different caesar
      if(findfreq(newtext)< lowest){ // find out the freq and compare with closket
          element = i;
	  lowest = findfreq(newtext);
      }
   }
   return encryptCaesar(text,element);
}

double findfreq(std::string text){
    int c = 0;
    double textFreq[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char alph[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    double Freq[26] ={0.082,0.015,0.028,0.043,0.13,0.022,0.02,0.061,0.07,0.0015,0.0077,0.04,0.024,0.067,0.075,0.019,0.00095,0.06,0.063,0.091,0.028,0.0098,0.024,0.0015,0.02,0.00074};
    int letterappear[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i =0;i<text.size();i++){
        for(int j=0;j<26;j++){
            if(tolower(text[i])==alph[j]){ // loop through and find the same letter
                letterappear[j]++;
		c++;
            }
        }
    }
    /*
    for(int i =0;i<26;i++){
        if(letterappear[i]>=1){ // how many letter there is 
            c++;
        }
    }
    */
    for(int i =0;i<26;i++){
      textFreq[i]= (double)letterappear[i]/c; // find the freq
    }
    double diff = 0;
    for(int i =0;i<26;i++){ // compare with the english freq.
      diff += sqrt((textFreq[i]*textFreq[i])+(Freq[i]*Freq[i]));
    }
    return diff;
}



