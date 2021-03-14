/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <iostream>

auto add(int a, int b) { return a + b; }

int main() {
  auto add_ptr = &add;

  auto sum = add_ptr(1, 2);

  std::cout << "add_ptr address " << &add_ptr << "\n";
  std::cout << "add_ptr result " << sum << "\n";

  std::cout << "add_ptr2 address " << &add_ptr2 << "\n";

}
