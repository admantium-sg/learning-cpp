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
#include <string>
#include <vector>

using namespace std;

class MathematicalShape {
  public:
    virtual void print() { cout << "I'm Shape" << endl;}
    virtual void infinity() final { cout << "Eternity" << endl; }
  protected:
    string secret{ "be66a9d624e0129906d64c6371330304" };
  
  friend class Optimum;
};

class Rectangle {
  public:
    int x;
    int y;
    int area() { return x* y; }
};

class Square : public Rectangle {
  public:
    void print() { cout << "Rectangle" << endl;}
};

class Quberical : public MathematicalShape, public Rectangle {
  public:
    using Rectangle::Rectangle; //inherit constructors
    void print() override { cout << "I'm Qube!" << endl; }
};

class Optimum {
  public:
    void accessFriend(MathematicalShape ms) {
      cout << "Optimums' Friend MathematicalShape has secret: " << ms.secret;
    }
};

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  // Initialization
  Square sq {2,3};
  cout << "Square with x=" << sq.x <<" y=" << sq.y << " has area=" << sq.area() << endl;

  //Upcasting
  Rectangle& rc_ref = sq;
  Rectangle* rc_ptr = &sq;

  cout << "Rectangle Ref with x=" << rc_ref .x <<" y=" << rc_ref .y << " has area=" << rc_ref .area() << endl;
  cout << "Rectangle Ptr with x=" << (*rc_ptr).x <<" y=" << (*rc_ptr).y << " has area=" << (*rc_ptr).area() << endl;

  //Downcasting
  Square& sq_ref = (Square&) sq;
  sq_ref.x = 4;
  cout << "Square Ref with x=" << sq_ref .x <<" y=" << sq_ref .y << " has area=" << sq_ref .area() << endl;
  
  Square* sq_ptr = (Square*) &sq;
  sq_ptr->y=5;
  cout << "Squar Ptr with x=" << (*sq_ptr).x <<" y=" << (*sq_ptr).y << " has area=" << (*sq_ptr).area() << endl;

  Quberical qube{};
  cout << "Qube with x=" << (*sq_ptr).x <<" y=" << (*sq_ptr).y << " has area=" << (*sq_ptr).area() << endl;
  qube.print();
  
  MathematicalShape& ms_ptr = (MathematicalShape&) qube;
  ms_ptr.print();
  ms_ptr.infinity();

  Optimum* opt = new Optimum{};
  cout << "Optimum" << endl;
  opt->accessFriend(ms_ptr);



}