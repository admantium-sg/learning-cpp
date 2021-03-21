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
#include <type_traits>
// #include <concepts>

using namespace std;

struct Book {
  int id;
  string title;
  bool borrowed;
};

// template <typename T>
// concept Library = requires(T a) {
//   a.get() -> std::is_array
// };

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  auto b = Book{1, "Effective C++", false};

}