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

  int* dyn_arr = new int[1];

  *(dyn_arr + 0) = 1;
  *(dyn_arr + 1) = 2;
  *(dyn_arr + 2) = 43;
  *(dyn_arr + 3) = 43;

  // for (auto x : dyn_arr) {
  //     cout << x << endl;
  // }

  for (int i = 0; i <= 3; i++) {
    cout << dyn_arr[i] << endl;
  }

  auto s = "Hello!";

  cout << s << endl;



}