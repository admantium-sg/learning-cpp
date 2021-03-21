/* 
* ---------------------------------------
* Copyright (c) Sebastian Günther 2021  |
*                                       |    
* devcon@admantium.com                  |    
*                                       | 
* SPDX-License-Identifier: BSD-3-Clause | 
* ---------------------------------------
*/
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <cstddef>

using namespace std;

template <typename T>
constexpr T sum(T x) {
  return x;
}

template<typename T, typename... Args>
constexpr T sum(T x, Args... args) {
  return x + sum(args...);
}

int main() {
  std::cout << "Folding of ints " << sum(1,3,5,6,7,14) << "\n";
}
