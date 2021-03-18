/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct Tracer {
  Tracer(const char* name):name{name}{
    cout << "Hello " << name << "\n";
  }
  ~Tracer() {
    cout << "Goodbye " << name << "\n";
  }
  const char* const name;
};

void runLinuxCmd() {
  string cmd{"ls -la ."};
  auto call = system(cmd.c_str());
  cout << call;
}

int main() {
  atexit([]{ cout << "Exit handler!" << endl;});

  Tracer t1{"T!"};
  Tracer t2{"T33"};

  // abort(); Exit programm, exit handler is not called



}