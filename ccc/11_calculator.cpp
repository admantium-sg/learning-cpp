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
#include <stdbool.h>

enum OpsEnum { add, sub, mult, div };

struct Calculator {
  Calculator(OpsEnum e) {
    ops = e;
  }

  OpsEnum getOps() {
    return ops;
  }

  int calculate(int i, int j) {
    switch (ops) {
      case (0): {
        return i + j;
      } break;
      case (1): {
        return i - j;
      } break;
      case (2): {
        return i * j;
      } break;
      case (3): {
        return i / j;
      } break;
    }
  }

  private:
    OpsEnum ops;
};

int main() {
  Calculator calc(OpsEnum::add);

  printf("MyCalc with ops <%d>", calc.getOps());

  Calculator c_add{OpsEnum::add};
  printf("AddCalc for [2, 8] = %d\n\r", c_add.calculate(2,8));

  Calculator c_mult = {OpsEnum::mult};
  printf("MultCalc for [2, 8] = %d\n\r", c_mult.calculate(2,8));

  Calculator c_div(OpsEnum::div);
  printf("DivCalc for [2, 8] = %d\n\r", c_div.calculate(8,2));
}