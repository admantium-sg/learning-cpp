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
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  vector<char> c_st_char{'H', 'e', 'l', 'i', 'u', 'm'};

  cout << "Vector[0] " << c_st_char[0] << endl; 
  cout << "Vector[3] " << c_st_char[3] << endl; 

  c_st_char.emplace(c_st_char.begin(), 'X');
  c_st_char.emplace_back('X');

  for (auto c : c_st_char) {
    cout << c << endl; 
  }
}