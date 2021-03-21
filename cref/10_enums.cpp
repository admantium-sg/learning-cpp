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

enum class Color {
  Red,
  Blue,
  Green
};

class ColorFactory{
  public:
    static int getInstances() { return instances;}
    static Color makeColor(Color c) { ColorFactory::instances++; return c;}
    static int instances;
};

int ColorFactory::instances = 0;

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  ColorFactory paint;

  Color r = paint.makeColor(Color::Red);
  Color g = paint.makeColor(Color::Green);

  cout << "Number of paints " << ColorFactory::getInstances() << endl;

  if (r == Color::Red) {cout << "Beautifull Red" << endl;}
  // if (r == 0) {cout << "Beautifull Red";} //throws error
}