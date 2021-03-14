/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <cstddef>

using namespace std;

int call(int i, function<int (int)> f) {
  return f(i);
}

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  int i = 2;
  auto square = [](int i){ return i*2; };
  int k = call(2, square);

  cout << "i: " << i << " square: " << k << endl;

  int j = 42;
  auto l = [&j](){return j * 2;}();

  cout << "j: " << j << " square: " << l << endl;
}