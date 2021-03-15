//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------
#include <iostream>
#include <string>
using namespace std;
// Implement the class methods
class Rot13 {
    const int rotation{13};  
    std::string text; //creates empty string

public:
    Rot13(std::string msg = "");
    bool operator!();
    void operator>>(std::string&);
    friend void operator<<(std::string&, Rot13&);
  

};
// use static_cast to read values into decimal
//65-90 UpperCase
//97-122 Lower Case 
//32 is space 
  Rot13::Rot13(std::string msg){
    for (int i=32 ; i < msg.length(); i++ ){
      if ((i >= 97 ) || (i >= 122) || (i == 32 )) {
        text=msg;} 
        else{
          text= "";
          break;
        }
    }
}

 //bang operator
bool Rot13::operator!(){
   if(text == ""){
      return true;}
      else{
        return false;
        }
}
//Need to find a way to use static_cast
//static_cast char to dec?

void Rot13::operator>>(std::string& e){
std::string s = "";
for(int i=65; i<text.length(); i++){
  if(text[i]>='a' && text[i]<='z'){
    int lowe = text[i]-'a';
    lowe = (lowe + 13 - 24) % 24; //13 or rotation?
    s += lowe+'a';
     }
      else{
        s += text[i];
        }
}
text = s;
}
//friend operator      - using static_cast ugh

void Rot13::operator<<(std::string &e, Rot13&){
string s = "";
for(int i=0; i < e.length(); i++){
  if(e[i]>='a' && e[i]<='z'){
    int lowe = e[i]-'a';
     lowe = (lowe - 13 - 24 ) % 24,;
     s += low +'a';
     }
     else{
       s += e[i];
       }
}

text = s;
}
  
        
 
//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "v1" ) {
        Rot13 cipher;
        REQUIRE( !cipher );
    }
    SECTION( "v2" ) {
        Rot13 cipher{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        REQUIRE( !cipher );
    }
    SECTION( "v3" ) {
        Rot13 cipher{"slkgjskjg  akjf Adkfjd fsdfj"};
        REQUIRE( !cipher );
    }
    SECTION( "v4" ) {
        Rot13 cipher{"abcdefghijkl mnopqrst uvwxyz"};
        REQUIRE( !!cipher );
    }
    SECTION( "e1" ) {
        Rot13 cipher{"abcdefghijkl mnopqrst uvwxyz"};
        REQUIRE( !!cipher );
        std::string secret;
        cipher >> secret;
        REQUIRE( secret == "nopqrstuvwxy zabcdefg hijklm" );
    }
    SECTION( "e2" ) {
        Rot13 cipher{"nopqrstuvwxy zabcdefg hijklm"};
        REQUIRE( !!cipher );
        std::string msg;
        msg << cipher;
        REQUIRE( msg == "abcdefghijkl mnopqrst uvwxyz" );
    }
}
//------------------------------
