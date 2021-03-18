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
#include <future>
#include <mutex>

using namespace std;

int unMutexRun() {
  size_t counter = 1000000;
  int things{};

  auto dec = async(launch::async, [&] {
    while (counter-- > 0) { 
      things--;
    }
  });

  auto inc = async(launch::async, [&] {
    while (counter++ < 100) { 
      things++;
    }
  });

  inc.get();
  dec.get();

  return things;
}

int mutexRun() {
  size_t counter = 1000000;
  int things{};
  mutex mut;

  auto dec = async(launch::async, [&] {
    while (counter-- > 0) { 
      mut.lock();
      things--;
      mut.unlock();
    }
  });

  auto inc = async(launch::async, [&] {
    while (counter++ < 1000000) { 
      mut.lock() ;
      things++;
      mut.unlock();
    }
  });

  inc.get();
  dec.get();

  return things;
}

int main(int argc, char* argv[]) {
  
  cout << "Number of args: " << argc << endl;
  for (int i=0; i < argc; i++) {
    cout << "Arg " << i << ": " << argv[i] << endl;
  }

  cout << "Unmutexed " << unMutexRun() << endl;
  cout << "Unmutexed " << unMutexRun() << endl;
  cout << "Unmutexed " << unMutexRun() << endl;
  
  cout << "Mutexed " << mutexRun() << endl;

  

  cout << "Goodbye!";
}