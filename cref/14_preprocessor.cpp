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

#define DEBUG
#include "14_Timer.h"

using namespace std;

int main(int argc, char* argv[]) {
  cout << "Compiled at " << __DATE__ << " " << __TIME__ << endl;
  cout << "Executing " << __FILE__ << endl;
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  Timer t{};
  cout << t.getCreationTime() << endl;

  cout << "EPOCH " << EPOCH_TIMER() << endl;

  cout << "DEBUG " << t.debug() << endl;
}