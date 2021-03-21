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
#include <filesystem>
#include <iomanip>

using namespace std;
using namespace std::filesystem;

int main(int argc, char* argv[]) {
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }
  path local{"./"};

  cout << "Listing files in DIR '" << local.string() << "'" << endl;

  for (auto item : directory_iterator{local}) {
    if (item.is_directory()) { 
      cout << " .*" << endl;
    } else {
      cout << item.path().filename().string() << " :: " << item.file_size() << " byte" << endl;
    }
  }

  cout << "Goodbye!";
}