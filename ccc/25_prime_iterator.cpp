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

struct PrimeIterator {
  PrimeIterator(int max): max{ max } {}
  bool operator!=(int x) {
    return x >= current;
  }
  PrimeIterator& operator++() {
    auto tmp = current;
    current += last;
    last = tmp;
    return *this;
  }
  int operator*() {
    return current;
  }
  PrimeIterator begin() {
    return *this;
  }
  int end() {
    return max;
  }
  private:
    int max{};
    int current{1};
    int last{1};
};

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  auto it = PrimeIterator{4000};

  for (const auto prime : it) {
    cout << prime << endl;
  }
}