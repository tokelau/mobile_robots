#include <iarduino_HC_SR04.h>
#include "Motors.h"

iarduino_HC_SR04 sensorForw(10,11); 
iarduino_HC_SR04 sensorSide(13,12); 

void setup() {
  Serial.begin(9600);
  for(int i = 4; i < 8; i++){
    pinMode(i, OUTPUT);  
  }
}

void loop() {
  int min_left = 10, max_left = 13, frwrd = 20;
  int fd = sensorForw.distance();
  int ld = sensorSide.distance();
  if(fd < frwrd) {
     while(fd < frwrd && ld > min_left || ld < max_left) {
      rightturn();
      ld = sensorSide.distance();
      fd = sensorForw.distance();
     }
  } else if(ld < min_left) {
    right();
  } else if(ld > max_left) {
    left();
    delay(90);
    forward();
  } else{
    forward();
  }
}
