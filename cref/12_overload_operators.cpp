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

class MagicNumber {
  public:
    MagicNumber(int val) : val{ val } {}
    
    explicit MagicNumber(string s) { 
      val = s.length();
    }

    operator int() { return 42;}

    MagicNumber operator+ (MagicNumber& other) {
      return MagicNumber{val + other.val + 42};
    }
    
    MagicNumber& operator++ () {
      val++;
      return *this;
    } 

    int val{};
};

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  MagicNumber zero{0};
  MagicNumber one{1};

  MagicNumber sum = zero + one;

  cout << "zero : " << zero.val << endl;
  cout << "one : " << one.val << endl;
  cout << "sum : " << sum.val << endl;

  ++sum;

  cout << "sum++ : " << sum.val << endl;

  MagicNumber tx0t{"Hello"};
  cout << "tx0t : " << tx0t.val << endl;
  
  
  cout << "Adding MagicNumbers : " << zero + 8 << endl;





  
}