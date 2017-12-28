#include <Wire.h>
#include <Adafruit_ADXL345_U.h>

#define SPEED_LEFT    6
#define DIR_LEFT      7
#define SPEED_RIGHT   5
#define DIR_RIGHT     4
#define SPEED         250

Adafruit_ADXL345_Unified sensor = Adafruit_ADXL345_Unified(12345);

float y = 0, x = 0, z = 0, z2 = 0;
bool state = true;
float xyz[3];

void forward() {
  analogWrite(SPEED_LEFT, SPEED);
  analogWrite(SPEED_RIGHT, SPEED);
  digitalWrite(DIR_LEFT, HIGH);
  digitalWrite(DIR_RIGHT, LOW);
  
}

void stop() {
  analogWrite(SPEED_LEFT, 0);
  analogWrite(SPEED_RIGHT, 0);
  digitalWrite(DIR_LEFT, HIGH);
  digitalWrite(DIR_RIGHT, LOW);
  
}

void calibrate(int n, float a_xyz[]) {
  sensors_event_t event;
  sensor.getEvent(&event);
  for (int i = 0; i < n; i++) {
    a_xyz[0] += event.acceleration.x;
    a_xyz[1] += event.acceleration.y;
    a_xyz[2] += event.acceleration.z;
    delay(10);
  }
  for (int i = 0; i < 3; i++) {
    a_xyz [i] /= n ;
  }
  
}

void setup () {
  #ifndef ESP8266
    while (!Serial);
  #endif

  Serial.begin(9600);
  Serial.println("Test");
  Serial.println("");
  if (!sensor.begin()) {
    Serial.println("Sensor is not detected :(");
    while (1);
  }
  sensor.setRange(ADXL345_RANGE_16_G);
  
  calibrate(200, xyz);
  for (int i = 4; i <= 7; i++)
      pinMode(i, OUTPUT);
  pinMode(13,OUTPUT);
}

void loop () {
  sensors_event_t event;
  sensor.getEvent(&event);
  x = event.acceleration.x - xyz[0];
  y = event.acceleration.y - xyz[1];
  z = event.acceleration.z - xyz[2];
  delay(200);
  
  Serial.println(z2-z);
  
  if (z2-z>=14) {
   if (state == true) {
      state = !state;
      digitalWrite(13, HIGH);
   }
   else {
    state = !state;
    digitalWrite(13, LOW); 
   }
  }
  z2 = event.acceleration.z - xyz[2];
  delay(200);
  
}


