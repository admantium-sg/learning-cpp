/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>
#include <atomic>

using namespace std;

atomic_bool interrupt{};

extern "C" void handler(int signal) {
  cout << endl ;
  cout << "Interupt!" << endl;
  interrupt = true;
}

int main() {
  signal(SIGINT, handler);

  while(!interrupt) {
    printf(".");
    this_thread::sleep_for(1s);
    cout << flush;
  }
}