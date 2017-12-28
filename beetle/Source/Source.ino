#include "Motors.h" 

#define SPEED 200

#define DL A0
#define DR A1

Motors motors; 

int DIR_LEFT = 4; 
int DIR_RIGHT = 7;
int SPEED_LEFT = 6;
int SPEED_RIGHT = 5;

 /* Значения для калибровки второго датчика */
int delta[16] = {3, 20, 5, 18, 25, 17, 12, 18, 29, 26, 32, 31, 50, 26, 20, 33};
enum STATES {FORWARD = 0, LEFT, RIGHT};

/*16 уровней освещенности*/
int mStep = 1024 / 16;
int state = FORWARD;

void setup() {
  motors.attach(DIR_LEFT, DIR_RIGHT, SPEED_LEFT, SPEED_RIGHT); 
  pinMode(DL, INPUT);
  pinMode(DR, INPUT);
  
  Serial.begin(9600);  

}

int getValue(int sensor) {
  int sen = analogRead(sensor);
  if(sensor == DL)
    return sen; //первый дачик возвращаем нормально
  else if (sensor == DR) {
    sen = sen + delta[sen / mStep]; //второй калибруем
    return sen;
  }
}

void getState() {
  int sL = getValue(DL);
  int sR = getValue(DR);
  if (sL == sR)
    state = FORWARD;
  if (sL < sR) 
    state = RIGHT;
  if(sL > sR)
    state = LEFT;  
}

void loop() {
  if (state == FORWARD) {
    motors.forward(SPEED);
    getState();
  } else if (state == RIGHT) {
    int sR = getValue(DR);
    do {
      motors.right();
    } while(sR / 2 > getValue(DL));
    do {
      motors.forward(SPEED);
    } while(getValue(DL) > getValue(DR));
    state = FORWARD;
  } else if(state == LEFT) {
    int sL = getValue(DL);
    do {
      motors.left();
    } while(sL / 2 > getValue(DR));
    do {
      motors.forward(SPEED);
    } while(getValue(DR) > getValue(DL));
    state = FORWARD;  
  }
}

