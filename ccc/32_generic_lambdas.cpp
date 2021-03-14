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

template <typename Fn, typename ty>
void transform(Fn fn, const ty* in, ty* out, size_t len) {
  for (int i=0; i<len; i++) {
    out[i] = fn(in[i]);
  }
}

int main(int argc, char *argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  auto translate = [](auto x){ return x*42 - 7;};

  const size_t len{2};
  const int in[]{1,2};
  int out[len];

  transform(translate, in, out, len);

  for (auto x : out) {
    cout << "OUT : " << x << endl;
  }

}