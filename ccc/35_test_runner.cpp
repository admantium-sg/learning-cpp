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

struct TestRunner {
  void run(void(*unit_test)(), const char* name) {
    try {
      unit_test();
      std::cout << "Test " << name << " is successfull" << std::endl;
    } catch(std::exception& e) {
      std::cout<< "EROROR " << name;
    }
  }
};

int main() {
  TestRunner runner = TestRunner();
  void(*lambda)();

  lambda = [](){"Hello Lambda";};
  runner.run(lambda, "Hello");
  
  void(*lambda2)(int);
  lambda2 = [](int x){
    if (x==0) throw "Fool";
  };
  runner.run(lambda, "Hello");
}
