#include "Motors.h"
#include <Arduino.h>

#define SPEED_1      5 
#define DIR_1        4
 
#define SPEED_2      6
#define DIR_2        7

void forward(){
  analogWrite(SPEED_1, 255);
  digitalWrite(DIR_1, HIGH);

  analogWrite(SPEED_2, 255);
  digitalWrite(DIR_2, HIGH);
}

void rightturn(){
  analogWrite(SPEED_1, 0);
  digitalWrite(DIR_1, LOW);

  analogWrite(SPEED_2, 255);
  digitalWrite(DIR_2, HIGH);
}

void left(){
  analogWrite(SPEED_1, 255);
  digitalWrite(DIR_1, HIGH);

  analogWrite(SPEED_2, 20);
  digitalWrite(DIR_2, HIGH);
}

void right(){
  analogWrite(SPEED_1, 20);
  digitalWrite(DIR_1, HIGH);

  analogWrite(SPEED_2, 255);
  digitalWrite(DIR_2, HIGH);
}

void right_slow(){
  analogWrite(SPEED_1, 0);
  digitalWrite(DIR_1, HIGH);

  analogWrite(SPEED_2, 255);
  digitalWrite(DIR_2, HIGH);
}

void backward(){
  analogWrite(SPEED_1, 255);
  digitalWrite(DIR_1, LOW);

  analogWrite(SPEED_2, 255);
  digitalWrite(DIR_2, LOW);
}

