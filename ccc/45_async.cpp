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
#include <future>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  auto fwdMsg = async([]{return "I'm Back!";});

  vector<int> vec{1,2,3,4,5};

  for (auto i : vec) {
    cout << i << endl;
  }

  cout << "FwdMsg: " << fwdMsg.get() << endl;

  cout << "Goodbye!";
}