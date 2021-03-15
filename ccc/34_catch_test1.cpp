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

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

template <class T>
constexpr T sum (T a, T b) {
  return a + b;
};

TEST_CASE("Sum ints") {
  REQUIRE (sum<int>(1,41) == 42);
  REQUIRE (sum<double>(2.3, 40.7) == 42.0);
}