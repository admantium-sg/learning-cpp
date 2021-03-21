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
#include <stddef.h>

int main() {
  char c; bool b; short s; int i; long l;
  
  printf("Bool: %zu\n", sizeof(b));
  printf("Char: %zu\n", sizeof(c));
  printf("Short: %zu\n", sizeof(s));
  printf("Int: %zu\n", sizeof(i));
  printf("Long: %zu\n", sizeof(l));

  printf("Long: %zu\n", sizeof(b));
}