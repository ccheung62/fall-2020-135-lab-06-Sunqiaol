#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "viginere.h"
#include "decrypt.h"
#include "decode.h"
// add your tests here

TEST_CASE("Test for shiftChar"){
    CHECK(shiftChar('a',25)=='z');
    CHECK(shiftChar('A',25)=='Z');
    CHECK(shiftChar('y',3)=='b');
    CHECK(shiftChar('Y',3)=='B');
    CHECK(shiftChar('b',12)=='n');
    CHECK(shiftChar('B',12)=='N');
    CHECK(shiftChar('S',10)=='C');
    CHECK(shiftChar('s',10)=='c');
}

TEST_CASE("test for encryptCaesar"){
    CHECK(encryptCaesar("Hello, World!",10) =="Rovvy, Gybvn!");
    CHECK(encryptCaesar("Sun Qiao Lin",2)=="Uwp Skcq Nkp");
    CHECK(encryptCaesar("Way to Go!",5)=="Bfd yt Lt!");
}

TEST_CASE("Test for encryptVigenere"){
    CHECK(encryptVigenere("Hello, World!","cake") == "Jevpq, Wyvnd!");
    CHECK(encryptVigenere("SunQiao Lin","abcd")== "SvpTibq Oio");
}

TEST_CASE("Test for reverse"){
    CHECK(shiftChar('a',-2)=='y');
    CHECK(shiftChar('z',-3)=='w');
    CHECK(shiftChar('Z',-25)=='A');
    CHECK(shiftChar('c',-5)=='x');
}

TEST_CASE("Test for decrypt"){
    CHECK(decryptCaesar("Rovvy, Gybvn!",10) == "Hello, World!");
    CHECK(decryptCaesar("Uwp Skcq Nkp",2)=="Sun Qiao Lin");
    CHECK(decryptCaesar("Bfd yt Lt!",5)=="Way to Go!");
    CHECK(decryptVigenere("Jevpq, Wyvnd!","cake")=="Hello, World!");
    CHECK(decryptVigenere("SvpTibq Oio","abcd")=="SunQiao Lin");
}

TEST_CASE("decode"){
    CHECK(automatic_decode("nochange")=="nochange");
    CHECK(automatic_decode("xzujwhfqnkwflnqnxynhjcunfqnithntzx")=="supercalifragilisticexpialidocious");
    CHECK(automatic_decode("XZujwhfqnkwflnqnxynhjcunfqnithntZX")=="SUpercalifragilisticexpialidocioUS");
    CHECK(automatic_decode("XZu jwhfqnkwflnqnxynhj,cunfqnith ntZX.")=="SUp ercalifragilistice,xpialidoc ioUS.");
    CHECK(automatic_decode("Vszzc,Kcfzr hvwg wg ob sloadzs ct oihcaohwq rsqcrs")=="Hello,World this is an example of automatic decode");
}

