/* 
* ---------------------------------------
* Copyright (c) Sebastian Günther 2021  |
*                                       |    
* devcon@admantium.com                  |    
*                                       | 
* SPDX-License-Identifier: BSD-3-Clause | 
* ---------------------------------------
*/
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <string>
#include <regex>

using namespace std;

typedef struct {
  int id;
  string title;
  bool borrowed;
} Book; 

ostream& operator<<(ostream& s, Book b) {
  s << "Book with props:\n"
    << "  ID        : " << b.id << "\n"
    << "  TITLE     : " << b.title << "\n"
    << "  AVAILABLE : " << !b.borrowed << endl;
  return s;
};

int main(int argc, char* argv[]) {
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  cout << "Is this " << boolalpha << true << " or " << false << "?" << endl;
  cout << "Let the Hex decide 0x" << hex << 255 << endl;
  cout << "And in oct? 0" << oct << 255 << endl;
  cout << "And in dec? " << dec << 0xff << endl;
  
  cout << "Print Struct type" << endl;

  Book ccc{42, "C++ Crash Course", true};

  cout << ccc;

  cout << "Goodbye!";
}