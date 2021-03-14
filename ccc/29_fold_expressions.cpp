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

template<typename... T>
constexpr auto sum(T... args) {
  return (... + args);
}

int main() {
  cout << "Folding of ints " << sum(1,3,5,6,7,14) << endl;
}
