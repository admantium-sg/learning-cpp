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
#include <string.h>

struct College {
  char name[100];
};

void print_name(College* c_ptr) {
  printf("This college is %s\n", c_ptr->name);
}

void print_all_names(College* c_ptr, size_t nr_cols) {
  printf("Iterating %d %d\n", nr_cols, 0);
  for(int i=0; i<nr_cols; i++) {
    printf("This college is %s\n", (c_ptr + i)->name);
  }
}

void print_int_arr1(int arr[]) {
  for(int i = 0; i <= sizeof(arr); i++) {
    printf("ARR[%d] : %d\n", i, arr[i]);
  }
};

void print_int_arr2(int* arr) {
  for(int i = 0; i <= sizeof(arr); i++) {
    printf("ARR[%d] : %d\n", i, *(arr + i));
  }
};

void print_int_arr3(int arr[]) {
  for(int i = 0; i <= sizeof(arr); i++) {
    printf("ARR[%d] : %d\n", i, arr[i]);
  }
};

int main() {
  int key_to_the_universe[]{2,4,5,7};
  int* uni_ptr = key_to_the_universe;
  
  printf("str is %d\n", key_to_the_universe[0]);
  printf("str pointer is %d\n", *uni_ptr);
  printf("str pointer +1 is %d\n", *uni_ptr + 1);
  printf("str pointer +3 is %d\n", *(uni_ptr + 3));
  printf("str pointer address is %p\n", uni_ptr);

  College cols[] = {"Boniface", "Pelby", "Marcian"};

  print_name(cols);
  print_all_names(cols, sizeof(cols) / sizeof(College));

  print_int_arr1(key_to_the_universe);
  print_int_arr2(key_to_the_universe);
}