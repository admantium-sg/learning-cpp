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

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  int i = 0;

  cout << "WHILE LOOP" << endl;

  while (i < 10) { cout << i++ << endl; }
  
  cout << "DO WHILE LOOP" << endl;

  do { cout << i++ << endl; } while (i < 20); 

  int a[]{1,2,3,4,5};

  for (int &i : a) { cout << i << endl;}
}