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
#include <regex>

using namespace std;

int main(int argc, char* argv[]) {
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  string yst("Cinematic Bios Thriller");

  auto yst_c = yst.c_str();

  cout << "C-String?! " << yst_c << endl;
  cout << "Null terminated: " << yst_c[yst.length()+1] << endl;

  cout << "C-Strings in C++ are iterators!" << endl;

  printf("C-String A: 0x%p\n", yst.c_str());
  printf("String Itr: 0x%p\n", yst.data());

  yst.insert(14, "hock");
  cout << "String manipulation: " << yst << endl;
  cout << "String finding ('ril'): " << yst.find("ril") << endl;

  regex reg{".*(ril).*"};

  cout << "Regex Count " << reg.mark_count() << endl;

  smatch res;
  auto matched = regex_match(yst, res, reg);

  cout << "Regex Match? " << matched << endl;
  cout << "Regex Results: " << res[0] << endl;
}