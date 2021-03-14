/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "stdio.h"
#include "stdexcept"
#include <iostream>

struct SimpleString {
  SimpleString(size_t max_size) : max_size{ max_size }, length{} {
      if (max_size == 0) {
        throw std::runtime_error{ "Max size must be at least 1"};
      }
      buffer = new char[max_size];
      buffer[0] = 0;
    }
  // CADRe - Constructor Acquires, Destructor Releases
  ~SimpleString() {
    buffer = 0;
  }

  bool appendLine(const char* x) {
    // if (strlen(x) + length + 2 > max_size) return false;
    std::strncpy(buffer + strlen(x), x, max_size - strlen(x));
    length += strlen(x);
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
  }

  void print() const {
    printf("%d : %d : %s", max_size, length, buffer);
    std::cout << buffer << "\n";
  }

  private:
    size_t max_size;
    char* buffer;
    size_t length;
  };

int main() {
  SimpleString s1 = SimpleString{100};
  SimpleString s2 = SimpleString{200};

  s1.appendLine("Hi!");
  s1.appendLine("Buenos Dias");

  s1.print();

  std::cout << "This is the end ...\n";
}