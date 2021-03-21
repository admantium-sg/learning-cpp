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
#include <iostream>

struct Tracer {
  Tracer(const char* name):name{name}{
    std::cout << "Hello " << name << "\n";
  }
  ~Tracer() {
    std::cout << "Goodbye " << name << "\n";
  }
  const char* const name;
};

int main() {
  Tracer t1{"T!"};
  Tracer t2{"T33"};
}