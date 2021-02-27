/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: GPL-3.0-only
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

  printf("The absolute value if %d is %d", i, absoluteNumber(i));
}
