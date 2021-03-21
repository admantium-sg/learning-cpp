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
#include <array>

using namespace std;

int main(int argc, char* argv[]) {
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  array<double,10> dart{1.0,2.0,3.0,4.0,42.0};

  for(auto it= dart.begin(); it != dart.end(); ++it) {
    cout << "Address: " << it << "| Value: " << *it << endl;
  }

  cout << "Using Range" << endl;

  for (auto i : dart) {
    cout << "Address: " << &i << "| Value: " << i << endl;

  }

  cout << "Using pointers" << endl;

  auto dart_ptr = dart.data();

  cout << "4th element: " << *(4 + dart_ptr) << endl;
}