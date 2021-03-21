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

  int* i_ptr;
  int i = 10;

  if (i_ptr != NULL) i_ptr = &i;
  i_ptr = &i;

  cout << "i_ptr " << *i_ptr << endl;

  i = 42;

  cout << "i_ptr " << *i_ptr << endl;

  int** i_ptr_ptr;


  i_ptr_ptr = &i_ptr;

  cout << "i_ptr_ptr " << **i_ptr_ptr << endl;

  i_ptr_ptr = nullptr;

  cout << "i_ptr_ptr " << i_ptr_ptr << endl;

  delete i_ptr_ptr;

  cout << "i_ptr_ptr " << i_ptr_ptr << endl;


}