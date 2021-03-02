/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include <stdexcept>
#include <cstdio>
#include <iostream>

enum class Direction {
  Forward,
  Backward,
  Stop
};

enum class MotorDriver {
  L293D,
  H298N,
};

struct Motor {
  virtual ~Motor() = default;
  virtual void drive(Direction) = 0;
};

struct DcMotor : Motor {
  DcMotor (MotorDriver motor_driver, int pin_a, int pin_b) 
    : motor_driver{motor_driver}, pin_a{pin_a}, pin_b{pin_b} {
       if (pin_a > 32 || pin_b > 32) {
        throw std::invalid_argument{" Pin numbers need to be less than 32" };
      }
  };

  // Prevent move and copy of objects
  DcMotor(const DcMotor&) = delete;
  DcMotor& operator=(const DcMotor&) = delete;
  DcMotor(DcMotor&& other) = delete;
  DcMotor& operator=(DcMotor&& other) = delete;

  ~DcMotor() {
    std::cout << "Terminating Motor\n";
  };

  void drive(Direction dir) override{
    switch (dir) {
      case Direction::Forward: {
        std::cout << "Driving forward... \n";
      } break;
      case Direction::Backward: {
        std::cout << "Driving backward...\n";
      } break;
      case Direction::Stop: {
        std::cout << "Stopping...\n";
      }
    }  
  }

  private:
    const MotorDriver motor_driver;
    const int pin_a;
    const int pin_b;
};

int main() {
  std::cout << "Starting programm... \n";

  DcMotor dc1 = DcMotor{MotorDriver::L293D, 15, 16};

  dc1.drive(Direction::Forward);
  dc1.drive(Direction::Backward);
  dc1.drive(Direction::Stop);
}