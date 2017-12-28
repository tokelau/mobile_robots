#include "Arduino.h"

class Motors {
public:
  int pin_dir_1;
  int pin_dir_2;
  int pin_speed_1;
  int pin_speed_2;
  int state;
  Motors();
  void attach(int pin1, int pin2, int pin3, int pin4);
  void go(int velocity, int right, int left);
  void go(int v1, int v2, int right, int left);
  void forward(int vel);
  void right();
  void backward();
  void left();
  void stopMotors();
  void accelerateRight(int velocity);
  void accelerateLeft(int velocity);
  };
