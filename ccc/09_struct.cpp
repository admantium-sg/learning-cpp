/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Book {
  char description[255];
  char date[11];
  int id;
  bool borrowed;
};

struct Book2 {
  void borrow() {
    borrowed = !borrowed;
  }
  char description[255];
  char date[11];
  int id;
  bool borrowed;
};

int main() {
  Book b;
  strcpy(b.description, "Neuromancer");
  strcpy(b.date, "2020-02-23");
  b.id = 1;
  b.borrowed = false;

  printf("Book1: description is < %s >\n", b.description);
  printf("Book1: date is < %s >\n", b.date);
  printf("Book1: id is < %d >\n", b.id);
  printf("Book1: borrows is < %d >\n", b.borrowed);

  Book b1 = {"Neuromancer", "2020-02-99", 2, false};

  printf("Book1: description is < %s >\n", b1.description);
  printf("Book1: date is < %s >\n", b1.date);
  printf("Book1: id is < %d >\n", b1.id);
  printf("Book1: borrows is < %d >\n", b1.borrowed);

  Book2 b2 = {"Ansible", "2020-02-23", 2, false};

  printf("Book2: description is < %s >\n", b2.description);
  printf("Book2: date is < %s >\n", b2.date);
  printf("Book2: id is < %d >\n", b2.id);
  printf("Book2: borrows is < %d >\n", b2.borrowed);

  Book2 b3 = {"Ansible 3", "2020-02-23", 2};

  printf("Book3: description is < %s >\n", b3.description);
  printf("Book3: date is < %s >\n", b3.date);
  printf("Book3: id is < %d >\n", b3.id);
}
