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

template <class T>
void tswap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template<class T, size_t size>
class Box {
  public:
    T store[size];
    T print() {return store[0];}
};

//Template specialization
template<>
class Box<bool, 10> {
  public:
    bool b;
    string print() { return (b ? "true" : "false");}
};

template<class T1, class ... Ts>
decltype(auto) sum(T1 first, Ts ... rest) {
  return first + sum(rest ...);
}

int main(int argc, char* argv[]) {
  cout << "Compiled at " << __DATE__ << " " << __TIME__ << endl;
  cout << "Executing " << __FILE__ << endl;
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  int i = 1;
  int j = 42;

  cout << "i = " << i << endl;
  cout << "j = " << j << endl;

  tswap<int>(i, j);

  cout << "i = " << i << endl;
  cout << "j = " << j << endl;

  Box<int, 10> b{};
  b.store[0] = i;
  b.store[1] = j;

  cout << "Box[0] = " << b.store[0] << endl;
  cout << "Box[1] = " << b.store[1] << endl;
  
  Box<bool,2> tbox{false};

  cout << "T-Box = " << tbox.print() << endl;

  cout << "SUM 1,4,42 = " << sum(1,4,42) << endl;

}