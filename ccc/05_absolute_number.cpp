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

using namespace std;

int absoluteNumber(int i) {
  if (i > 0) return i;
  return i * -1;
}

int main() 
{
  int i = -9;

  printf("The absolute value of %d is %d", i, absoluteNumber(i));
}
