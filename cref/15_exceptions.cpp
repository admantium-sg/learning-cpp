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

void inpar() noexcept {cout << "I will never throw!" << endl;}

int unbar(int x, int y) {
  if (y == 0) throw exception();
  return x/y;
}

int main(int argc, char* argv[]) {
  cout << "Compiled at " << __DATE__ << " " << __TIME__ << endl;
  cout << "Executing " << __FILE__ << endl;
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  try {
    unbar(42.43, 0);
  }
  catch (exception& e ) {
    cout << "ERROR: " << e.what() << endl;
  }

  cout << "Holding on!" <<endl;

}