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

struct Timer {
  bool add(int i) {
    if (i < 24) return true;
    return false;
  }
};

int main(int argc, char* argv[]) {
  using PM = Timer;

  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  cout << "Timer true ?" << Timer{}.add(2) << endl;
}