/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <cstddef>

using namespace std;

struct Book {
  int id;
  string title;
  bool borrowed;
};

int main(int argc, char* argv[]) {
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  Book b{1, "Effective C++", false};

  cout << "Book : " << b.id << " " << b.title << " " << b.borrowed << endl;

  auto [id, title, borrowed] = b;

  cout << "Book : " << id << " " << title << " " << borrowed << endl;

}