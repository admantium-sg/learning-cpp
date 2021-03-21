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

  auto ptr = SimpleUniquePointer<Book>{ &b };

  cout << ptr.get()->title << endl;
}