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

void pass_by_value(int i) { i += 42;};
void pass_by_ref(int& i) { i += 42;};
void pass_by_ptr(int* i) { *i += 42;};

int& ret_ref(int& i) { return(i += 42);};
int* r_ptr(int* i) { return(i) ;};
// void ret_ptr(int* i) { *i += 42;};

decltype(auto) getRef(int x) { return x; };

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  int i = 0;
  
  cout << "pass by value: " << i << " => ";
  pass_by_value(i);
  cout << i << endl;

  cout << "pass by ref: " << i << " => ";
  pass_by_ref(i);
  cout << i << endl;

  cout << "pass by ptr: " << i << " => ";
  pass_by_ptr(&i);
  cout << i << endl;

  cout << "ret ref: " << i << " => ";
  int j_ref = ret_ref(i);
  cout << j_ref << endl;
  i++;
  cout << j_ref << endl;
  cout << i << endl;

  cout << "ret ptr: " << i << " => ";
  int* k = r_ptr(&i);
  cout << k << " " << *k << endl;
  cout << *r_ptr(&i) << endl;

  cout << "getRef: " << i << " => ";
  cout << getRef(i+1) << endl;
  cout << i << endl;

  
}