/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */
#include <stdio.h>

int main() {
  int i = 100;
  int* i_ptr = &i; // i_ptr points to i address

  printf("i is %d\n", i);
  printf("i_ptr value is %d\n", *i_ptr); // *i_ptr dereferences the pointer, access its value
  printf("i_ptr memory address is %p\n", i_ptr);

  i = 200;

  printf("i is %d\n", i);
  printf("i_ptr value is %d\n", *i_ptr);
}