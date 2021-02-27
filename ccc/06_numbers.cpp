/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include <stdio.h>

int main() {
  unsigned short i_b = 0b1100;
  int i_h = 0x144;
  signed long i_o = 0123;
  int i_d = 255UL;

  printf("Binary %hu :: Hex %d :: Octal %ld\n", i_b, i_h, i_o);
  printf("Decimal to HEX 0X%x and OCT 0%o\n", i_d, i_d);
  printf("\u0372\u03B1\u03BCr\u03BCs ");
}