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
#include <forward_list>

using namespace std;

int main(int argc, char* argv[]) {
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  forward_list<int> primes{1,2,4,5,7};

  auto only_forward = primes.begin();
  cout << "Primes: " << *only_forward << endl;
  only_forward++;
  only_forward++;
  only_forward++;
  cout << "Primes: " << *only_forward << endl;
  only_forward++;
  only_forward++;
  // cout << "Primes: " << *only_forward << endl; Seg Fault!

  // only_forward--; Error: can not decrement value e


}