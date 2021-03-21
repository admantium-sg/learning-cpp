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

struct Clock {
  int time{};
  void incr_time() {
    time ++;
  }
};

int main() {
  Clock c{time: 2014};
  Clock* c_ptr = &c;

  printf("Clock year is %d\n", c.time);
  printf("Clock pointer year is %d\n", *c_ptr);

  printf("Changing the Clocks member 'year' via a pointer member access \n");
  c_ptr->time = 2222;
  
  printf("Clock year is %d\n", c.time);
  printf("Clock pointer year is %d\n", *c_ptr);
  
  printf("Changing the Clocks member 'year' via the objects \n");
  
  c.time = 1200;
  
  printf("Clock year is %d\n", c.time);
  printf("Clock pointer year is %d\n", *c_ptr);

  int* c_t_ptr = &c_ptr->time;
  (*c_t_ptr)++; 
  
  printf("Clock year is %d\n", c.time);
  printf("Clock pointer year is %d\n", *c_ptr);
}