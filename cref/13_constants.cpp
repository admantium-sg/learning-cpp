/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <cstddef>

using namespace std;

class ConstClass {
  public:
    void hello() const { cout << "Hello" << endl; };
    void hi() {cout << "hi" << endl; }
};

int main(int argc, char* argv[]) {
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  string h{"Hello"};

  string* const h_ptr = &h;

  cout << "h_ptr " << *h_ptr << endl;

  // h_ptr = &"Fool!"; //variable 'h_ptr' declared const here  
  const string* h_ptr2 = &h; 

  string j{"Fool!"};

  const string& j_ref = j;
  cout << "j_ref " << j_ref << endl;

  j = "Cool!";
  cout << "j_ref " << j_ref << endl;

  const ConstClass a, b;
  ConstClass c;

  a.hello(); 
  //a.hi() // throws  member function 'hi' has type 'const ConstClass

  // a = c; // throws this' argument has type 'const ConstClass', but method is not marked
      
  


}