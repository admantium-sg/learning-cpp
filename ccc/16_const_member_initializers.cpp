/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>

struct Element {
  char id{};
  int year{};
  
  Element(char id_arg, int year_arg) 
    : id{id_arg}, year{year_arg} {}
  
  void incrYear() {
    this->year++;
  }

  int getYear() const {
    return year;
  }
  
  void print() {
    printf("I am element %c%d opertional until ...\n", id, year);
  }
};

int main() {
  Element alpha = Element('A', 112);
  alpha.print();

  alpha.incrYear();

  printf("YEAR is %d", alpha.getYear());
}