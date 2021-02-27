/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include <stdio.h>
#include <stddef.h>

int main() {
  char arr_c[] = {'H', 'e', 'l', 'l', 'o'};
  char str[] = "Hello";

  printf("Char at [2]: %c\n", arr_c[2]);
  printf("Char at *(arr_c + 2): %c\n", *(arr_c + 2));
  printf("Str: Char at *(arr_c + 2): %c\n", *(str + 2));

  int i_c[] = {12, 1353 ,1335, 1345 ,15364, 14};

  for (int v : i_c) printf("i_c :: 0x%x\n", v);  

  size_t i_c_nr = sizeof(i_c) / sizeof(int);
  printf("Size of ic: %lu\n", i_c_nr);

  int max = 0;
  for (size_t i = 0; i < i_c_nr; i++) {
    if (max <= *(i_c + i)) max = *(i_c + i);
  }

  printf("Max Value in i_c[] is %d", max);
}