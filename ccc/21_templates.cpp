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

template<typename T>
T means(T* values, size_t length) {
  T sum{};
  
  for (int i = 0; i <= length; i++) sum += values[i];
  std::cout << "Sum: " << sum << "Means: " << sum/length << "\n";
  
  return sum / length;
}

int main() {
  int i[] = {1,3,5,6,7,14};
  double d[] = {1.0,3.0,5.0,6.0 };
  float f[] = {1.0f,3.0f,5.0f,6.0f };

  std::cout << "Means of ints " << means<int>(i, 6) << "\n";
  std::cout << "Means of double " << means<double>(d, 4) << "\n";
  std::cout << "Means of float " << means<float>(f, 4) << "\n";
}
