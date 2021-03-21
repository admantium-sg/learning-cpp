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
#include <cstddef>
#include <iostream>

#pragma message("EPOCH TIMER rocks!")

#ifndef TIMER
#define TIMER

#define EPOCH_TIMER() ("1970-01-01")
#define STEPPER(x)\
if (x > 5) return 1; 

using namespace std;

class Timer {
  
  public:
    void getTime();
    std::string getCreationTime() {return createdAt;};
    #if defined DEBUG
    std::string debug() { return "0XCoffee"; } 
    #endif
  private:
    std::string createdAt{__DATE__};
};

#endif