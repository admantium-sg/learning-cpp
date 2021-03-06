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

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

template <class T>
constexpr T sum (T a, T b) {
  return a + b;
};

TEST_CASE("Sum ints") {
  REQUIRE (sum<int>(1,41) == 42);
  REQUIRE (sum<double>(1.3, 40.7) == 42.0);
}