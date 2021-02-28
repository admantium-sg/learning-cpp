/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Clock {
  int year;
  void incrYear() {
    year++;
  }
};

struct ClockConstructor {
  int year;
  ClockConstructor(int year_arg) {
    if(!setYear(year_arg)) year = 2019;
    else year = year_arg;
  };

  bool setYear(int year_arg) {
    if (year_arg < 0) return false;
    year = year_arg;
    return true;
  }
  void incrYear() {
    year++;
  }
};

int main() {
  Clock c{2021};

  printf("Clock 1 %d\n", c.year);
  ClockConstructor c2{2021};
  printf("Clock 2 \n");
  
  ClockConstructor c3(2021);
  printf("Clock 3 %d\n", c3.year);
  ClockConstructor c4(-2021);
  printf("Clock 4 %d\n", c4.year);

}

