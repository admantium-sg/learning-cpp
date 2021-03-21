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

struct LambdaFactory {
  LambdaFactory(char in) : to_count{ in }, tally{} {}

  auto make_lambda() {
    return [this](const char* str) {
      size_t index{};
      size_t result{};

      while(str[index]) {
        if (str[index] == to_count) result++;
        index++;
      }
      tally += result;
      return result;
    };
  }
  const char to_count;
  size_t tally;
};

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  // for (int i=0; i <= argc; i++) {
  //   cout << "Arg " << i << ": " << argv[i] << endl;
  // }

  LambdaFactory count_s{'s'};
  auto lambda = count_s.make_lambda();

  cout << "Tally :" << count_s.tally << endl;
  cout << "Count :" << lambda("Super Duper Market Mutants") << endl;
  cout << "Tally :" << count_s.tally << endl;
  cout << "Count :" << lambda("super super Markets Mutants") << endl;
  cout << "Tally :" << count_s.tally << endl;

  cout << "Lambda Returns " << [](int x, double y) -> decltype(x + y) { return x+y;} << endl;
}
