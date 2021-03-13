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

  char* c_str = "Hello";

  cout << c_str << endl;

  string d = (string)c_str + " World!";

  cout << d << endl;

  int i = 0;

  (i < 5) ? i = 0 : i = 10;

  cout << i << endl;

}