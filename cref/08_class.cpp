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
#include <string>
#include <vector>

class Test {
  public:
    int x;
    int y;
    Test () { x = 10; y = 20; };
    Test(int x, int y) : x{ x }, y{ y } {};

    // Test(const Test&) = delete;
    // Test& operator=(const Test&) = delete;
};

// Initializer list
class Igniter {
  public:
    Igniter(std::initializer_list<char> args) {
      for (auto arg : args) {
        std::cout << arg << std::endl;
      }
    }
};

using namespace std;

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  Test t;
  cout << "T : x => " << t.x << endl;

  Test t2{42,4};
  cout << "T2 : x => " << t2.x << endl;
  
  //direct initialization
  Test t3(1,2); 
  
  //value initialization
  const Test& t4 = Test(2,3);
  cout << "T4 : x => " << t4.x << endl;
  
  //copy initialization
  Test t5;
  t5 = t4; 
  
  // New initialization
  Test* t6 = new Test(100,200);
  cout << "T6 : x => " << t6->x << endl;

  // Uniform initialization
  Test t7 {222, 456};

  vector<string> box { "one", "box"};
  cout << "Box : 0 => " << box[0] << endl;

  // Uniform copy constructor
  Test t8 { t7 };
  cout << "T8 : x => " << t6->x << endl;

  Igniter igni{'1', '2', '3'};


}