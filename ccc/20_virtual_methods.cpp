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

struct Shape {
  virtual ~Shape () = default;
  virtual int area() = 0;
  virtual void print() = 0;
  virtual std::string stats() = 0;
};

struct Circle : Shape {
  Circle(int x, int y) 
    : x{x}, y{y} {
  }

  ~Circle() {
    std::cout << "Terminating Circle";
  }

  int area() override {
    return 3.144 * (double) x * (double) y;
  }

  void print() override {
    std::cout << "Circle";
  }

  std::string stats() override {
    return "Circle";
  }

  private:
    int x{};
    int y{};
};

struct Tracer {
  Tracer(Shape& s) 
    : s{s} {
  }

  ~Tracer() {
    std::cout << "Tracer is gone ... " << s.stats() << "\n";
  }

  private:
    Shape& s;
};

int main() {
  Circle c = Circle(2,2);
  int area = c.area();

  std::cout << "Area of circle is " << area << "\n";

  Tracer t1 = Tracer(c);
}