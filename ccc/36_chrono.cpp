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
#include <climits>

using namespace std;

int main(int argc, char* argv[]) {
  chrono::high_resolution_clock c{};
  auto start = c.now();

  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  for(int i = 0; i < 4444; i++) {
    cout << i << " ";
  }
  cout << endl << endl;

  auto end = c.now();
  chrono::duration<double, milli> dur = end - start;

  cout << "Duration: " << dur.count() << endl;
}