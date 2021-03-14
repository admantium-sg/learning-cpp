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

template <typename T>
struct SimpleUniquePointer {
  SimpleUniquePointer() = default;
  SimpleUniquePointer(T* pointer) : pointer{ pointer } {}
  ~SimpleUniquePointer() { if(pointer) delete pointer;}

  SimpleUniquePointer(const SimpleUniquePointer&) = delete;
  SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete;

  SimpleUniquePointer(SimpleUniquePointer&& other) noexcept 
    : pointer{ other.pointer } {
      other.pointer = nullptr;
    }

  SimpleUniquePointer& operator=(SimpleUniquePointer&& other) noexcept {
    if(pointer) delete pointer;
    pointer=other.pointer;
    other.pointer=nullptr;
    return *this;
  }

  T* get() {
    return pointer;
  }

  private:
    T* pointer;
};

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

  auto b = Book{1, "Effective C++", false};

  auto ptr = SimpleUniquePointer{ &b };

  cout << ptr.get()->title << endl;
}