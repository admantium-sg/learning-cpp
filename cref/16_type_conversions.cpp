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

using namespace std;

int main(int argc, char* argv[]) {
  cout << "Compiled at " << __DATE__ << " " << __TIME__ << endl;
  cout << "Executing " << __FILE__ << endl;
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  try {
    int i = 5;
    char c = 'A';
    int* i_ptr;

    i_ptr = &i;
    i_ptr = (int*) &c; //C-Style cast
    cout << "What is i_ptr? " << i_ptr <<  " " << *i_ptr << endl;
    
    // i_ptr = static_cast<int*>(&c); compile error static_cast from 'char *' to 'int *'
    i_ptr = reinterpret_cast<int*>(&c);
    cout << "What is i_ptr? " << i_ptr <<  " " << *i_ptr << endl;

    const int j = 42;
    int* j_ptr = const_cast<int*>(&j);
    cout << "What is j_ptr? " << j_ptr <<  " " << *j_ptr << endl;
    
    *j_ptr = 43;
    cout << "What is j_ptr? " << j_ptr <<  " " << *j_ptr << endl;
    cout << "What is j? " << j << endl;
  }
  catch (exception& e ) {
    cout << "ERROR: " << e.what() << endl;
  }


}