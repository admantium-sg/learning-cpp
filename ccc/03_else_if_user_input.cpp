/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>

int main() {
  int *x;

  printf("Please input a number: \n");
  scanf("%d", x);

  if (*x < 42) printf("X < 42");
  else if (*x == 42) printf("The answer to it all");
  else printf("X is greater than 42");
}