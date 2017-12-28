#include "Motors.h"

#define STATE_STOP 0
#define STATE_FORWARD 1
#define STATE_LEFT 2
#define STATE_RIGHT 3
#define STATE_BACKWARD 4

#define K_BREAK_SPEED 4

Motors::Motors() {}

void Motors::attach(int pin1, int pin2, int pin3, int pin4) {
  pin_dir_1 = pin1; 
  pin_dir_2 = pin2; 
  pin_speed_1 = pin3; 
  pin_speed_2 = pin4;
  pinMode(pin_dir_1, OUTPUT);
  pinMode(pin_dir_2, OUTPUT);
  pinMode(pin_speed_1, OUTPUT);
  pinMode(pin_speed_2, OUTPUT);  
}

void Motors::go(int velocity, int right, int left) {
  digitalWrite(this -> pin_dir_1, right);
  digitalWrite(this -> pin_dir_2, left);
  analogWrite(this -> pin_speed_1, velocity);
  analogWrite(this -> pin_speed_2, velocity); 
}

void Motors::go(int v1, int v2, int right, int left) {
  digitalWrite(this -> pin_dir_1, right);
  digitalWrite(this -> pin_dir_2, left);
  analogWrite(this -> pin_speed_1, v1);
  analogWrite(this -> pin_speed_2, v2); 
}

void Motors::forward(int vel) {
  this -> state = STATE_FORWARD;
  this -> go(vel, vel, 0, 1);
}

void Motors::right() {
  this -> state = STATE_RIGHT;
  this -> go(200, LOW, HIGH);
}

void Motors::backward() {
  this -> go(228, LOW, LOW);
}

void Motors::left() {
  this -> state = STATE_LEFT;
  this -> go(200, HIGH, LOW);
} 

void Motors::stopMotors() {
  this -> go(0, LOW, LOW);
}

void Motors::accelerateRight(int velocity) {
  digitalWrite(this -> pin_dir_1, LOW);
  digitalWrite(this -> pin_dir_2, LOW);
  analogWrite(this -> pin_speed_1, velocity);
  analogWrite(this -> pin_speed_2, velocity / K_BREAK_SPEED); 
}

void Motors::accelerateLeft(int velocity) {
  digitalWrite(this -> pin_dir_1, HIGH);
  digitalWrite(this -> pin_dir_2, HIGH);
  analogWrite(this -> pin_speed_1, velocity / K_BREAK_SPEED);
  analogWrite(this -> pin_speed_2, velocity); 
}
