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
  virtual void drive(Direction, unsigned int) = 0;
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

  void drive(const Direction dir, const unsigned int duration) override{
    switch (dir) {
      case Direction::Forward: {
        std::cout << "Driving forward... " << this->speed << " for duration " << duration << "ms \n";
      } break;
      case Direction::Backward: {
        std::cout << "Driving backward..." << this->speed << " for duration " << duration << "ms \n";
      } break;
      case Direction::Stop: {
        std::cout << "Stopping..." << this->speed << " for duration " << duration << "ms \n";
      }
    }  
  }


  bool set_speed(uint speed) {
    if (speed > 255) throw std::invalid_argument{"Speed can not be greater than 255"};
    this->speed = speed;
    return true;
  }

  private:
    const MotorDriver motor_driver;
    const int pin_a;
    const int pin_b;
    uint speed;
};

int main() {
  std::cout << "Starting programm... \n";

  DcMotor dc1 = DcMotor{MotorDriver::L293D, 15, 16};

  dc1.drive(Direction::Forward, 10);
  dc1.drive(Direction::Backward, 5);
  dc1.drive(Direction::Stop, 500);

  dc1.set_speed(200);
  dc1.drive(Direction::Forward, 10);
  dc1.drive(Direction::Backward, 55);


}