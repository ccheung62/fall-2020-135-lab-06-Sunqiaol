#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "viginere.h"
#include "decrypt.h"

using namespace std;
int main()
{
  test_ascii("hello");
  char word = shiftChar('b',2);
  cout<<word<<endl;

  string result = encryptVigenere("Hello, World!","cake");
  cout<<result<<endl;
  return 0;

  result == decryptCaesar("Rovvy, Gybvn!",10);
  cout<<result<<endl;
  
}
