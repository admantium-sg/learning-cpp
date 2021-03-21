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

int stepper(int digit) {
  if (digit < 0) return -1;
  if (digit > 0) return 1;
  return digit;
}

int main() {
  int *x;

  printf("Please input any number: \n");
  scanf("%d", x);

  int stp = stepper(*x);

  printf("Inserted value <%d> is in stepper <%d>", *x, &stp);
}