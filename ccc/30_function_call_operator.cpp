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

struct Callable {
  Callable(string msg): msg{msg} {};
  string operator()(const string a) { return msg + "::" + a;};
  string msg;
};

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i <= argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  function<void()> v_func;
  
  try {
    v_func();
  } catch (bad_function_call& e) {
    cout << "Called void function" << endl;
  }

  function<string()> l_func { []{return "true";} };

  cout << "Call bool lambda " << l_func() << endl;

  // function<string()> s_func {Callable{"Hello"}};

  cout << "Call callable function call operator " << Callable{"Hello"}("Fool") << endl;

}
