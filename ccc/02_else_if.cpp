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

int main() {
  int x = 43;
  if (x <= 42) printf("X < 42");
  else if (x == 42) printf("The answer to it all");
  else printf("X is greater than 42");
}