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
#include <string.h>

struct Element {
  char id{};
  int year{};
  Element* next{};
  
  Element(char id_arg, int year_arg) : id{id_arg}, year{year_arg} {}
  
  void setNext(Element* linked_element) {
    linked_element->next = this->next;
    next = linked_element;
  }
  
  void print() {
    printf("I am element %c%d opertional until %4.0f\n", id, (double) year/304.42);
  }
};

int main() {
  Element alpha = Element('A', 112);
  Element beta = Element('B', 2034);
  Element gamma = Element('R', 0XC0FFEE);

  alpha.setNext(&beta);
  beta.setNext(&gamma);

  for (Element* cursor = &alpha; cursor; cursor = cursor->next) {
    (*cursor).print();
  }
}


// *(int *) i_ptr = 0xFF