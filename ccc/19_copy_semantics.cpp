/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */
#include <stdio.h>
#include <stdexcept>
#include <iostream>

struct Character {
  Character(std::string name, int str, int agl, int itl) : 
    name{name}, str{str}, agl {agl}, itl {itl} {
  }
  
  void print() {
    std::cout << name << " | STR: " << str << "| AGL: " << agl << "| INT: " << itl << "\n";
    if(nrOfItems > 0) std::cout << "Items: ";
    for (int i = 0; i < nrOfItems; i++) {
      std::cout << items[i] << " | ";
    }
    std::cout << "\n";
    
  }
 
  // Goal: reset name and items, keep attribiutes
  Character& operator=(const Character& other) {
    if( this == &other) return *this;
    name = other.name;
    str = other.str + 1;
    agl = other.agl;
    itl = other.itl;
    return *this;
  }

  ~Character() {
    std::cout << "Goodbye from " << name << "\n";
  }

  bool addItem(std::string item_name) {
    if (nrOfItems >= maxItems) return false;
    items[nrOfItems] = item_name;
    nrOfItems ++;
    return true;
  }

  private:
    std::string name{};
    int str{};
    int agl{};
    int itl{};
    static const int maxItems = 6;
    int nrOfItems = 0;
    std::string items[maxItems];
};

int main() {
  Character barbar = Character("Groot", 10, 6, 2);
  Character magican = Character("Teclis", 4, 4, 10);

  magican.addItem("Mana Potion");
  magican.addItem("Staff");

  barbar.print();
  magican.print();

  std::cout << "Create and Print the Bard\n";
  Character bard = magican;
  bard.addItem("Harp");

  bard.print();
  std::cout << "Goodbye!\n";
}