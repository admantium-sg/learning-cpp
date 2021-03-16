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
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }
  
  set<char> msg{'H', 'e', 'l', 'p', 'u', 'm'};

  cout << "Size of msg is: " << msg.size() << endl;

  for (auto c : msg) {
    cout << c << endl; 
  }

  cout << "Find 'l': " << *msg.find('l') << endl;

  auto it = msg.equal_range('m');

  cout << "IT first: " << *it.first << endl;
  cout << "IT second: " << *it.second << endl;
}