/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: GPL-3.0-only
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
  int j = ret_ref(i);
  cout << j << endl;
  i++;
  cout << j << endl;

  cout << "ret ptr: " << i << " => ";
  int* k = r_ptr(&i);
  cout << k << " " << *k << endl;
  cout << *r_ptr(&i) << endl;

  
}