#define pin_r 9
#define pin_g 10
#define pin_b 11
#define BUTTON 2

#include <EEPROM.h>

enum COLORS {YELLOW, ORANGE, PURPLE, WHITE, GREEN, BLUE};

int R, G, B;
int current, state, lastState;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
  pinMode(pin_r, OUTPUT);
  pinMode(pin_g, OUTPUT);
  pinMode(pin_b, OUTPUT);

  /***********************
   * EEPROM.put(0, 1);
   **********************/

   current = EEPROM.get(0, current);
   Serial.print("Current Color is: ");
   Serial.println(current);
   onShowColor(current);

}

unsigned long start = 0, End = 0, timeHold = 0;

void loop() {
  
  /*state = digitalRead(BUTTON);

  if (state != lastState) {
      if (state == HIGH) {
          start = millis();         
      } else {
        End = millis();
        timeHold = End - start;

        Serial.println(timeHold);

          if (timeHold >= 20 && timeHold < 2000) 
            onShowColor(current);
          else {
            decColor();
            EEPROM.put(0, current);
            Serial.print("Color Saved! = ");
            Serial.println(current);
            incColor();
          }
      }
  }

  lastState = state;*/
  onShowColor(-5);
  delay(50);
  analogWrite(pin_r, 0);
  analogWrite(pin_g, 0);
  analogWrite(pin_b, 0);
  delay(50);
  onShowColor(BLUE);
  delay(50);
  
}

void incColor() {
  Serial.print("Increment: ");
  Serial.println(current);
  if (current != BLUE)
    current++;
  else current = YELLOW;
}

void decColor() {
  if (current == YELLOW)
    current = BLUE;
  else current--;
  Serial.print("Decrement: ");
  Serial.println(current);
}

void onShowColor(int color) {
  switch (color) {
    case YELLOW:
    Serial.println("Yellow");
      R = 255;
      G = 255;
      B = 0;
      break;
    case ORANGE:
    Serial.println("Orange");
      R = 255;
      G = 165;
      B = 0;
      break;
    case PURPLE:
    Serial.println("Purple");
      R = 255;
      G = 0;
      B = 255;
      break;
    case WHITE:
    Serial.println("White");
      R = 255;
      G = 255;
      B = 255;
      break;
    case GREEN:
    Serial.println("Green");
      R = 0;
      G = 255;
      B = 0;
      break;
    case BLUE:
    Serial.println("Blue");
      R = 0;
      G = 0;
      B = 255;
      break;
    default:
    Serial.println("Default");
      R = 255;
      G = 0;
      B = 0;
      break;
  }
  analogWrite(pin_r, R);
  analogWrite(pin_g, G);
  analogWrite(pin_b, B);
  incColor();
}

