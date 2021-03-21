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
#include <optional>

using namespace std;

struct Timer {
  long time;
};

struct Command {
  function<void()> f;
};

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  Timer t{20210315};
  Command c{function<void()>{[](){cout << "Dont call us!" <<endl;}}};

  c.f();

  pair<Timer, Command> p{t,c};

  cout << "Pair first " << p.first.time << endl;
  cout << "Command Address is  " << &c << endl;
  cout << "Pair 2nd Address is " << &p.second << endl;


  tuple<string,Timer,Command> tup{"Utrecht", t, c};

  cout << "Tuple 1 " << get<string>(tup) << endl;
  cout << "Tuple 2 " << get<1>(tup).time << endl;
}