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
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  //rvalue ref
  int&& ref = 1+2;

  cout << "REF " << ref << endl;

  int* ptr = &ref;
  cout << "PTR addr " << ptr << endl;
  cout << "PTR val " << *ptr << endl;

  ref += 42;
  cout << "REF " << ref << endl;
  cout << "PTR addr " << ptr << endl;
  cout << "PTR val " << *ptr << endl;

  int* x = new int(1);
  int& sref = *x;
  cout << "REF " << sref << endl;

  if (x != NULL) x = new int(22);
  cout << "REF " << sref << endl;
}