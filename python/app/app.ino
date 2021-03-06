#define GREEN 11
#define RED 10
#define BLUE 9
#define PR A1

String s_byte = "";
int result;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(PR, INPUT);
  ledOff();
  //Serial.println("Input commad On/Off");
}

void loop(){
  while (Serial.available() > 0) {
    s_byte += (char)Serial.read();
    //Serial.print("Incoming byte: ");
    //Serial.println(s_byte);
  }
  if (s_byte == "OnFirst") {
    first(); 
    delay(500);
    s_byte = "";
  }
  if (s_byte == "OnSecond") {
    second(); 
    delay(500);
    s_byte = "";
  }
  if (s_byte == "OnThird") {
    thrid(); 
    delay(500);
    s_byte = "";
  }
  if (s_byte == "OnFourth") {
    fourth(); 
    delay(500);
    s_byte = "";
  }
  if (s_byte == "OnFifth") {
    fifth(); 
    delay(500);
    s_byte = "";
  }
  if (s_byte == "Off") {
    ledOff();
    s_byte = "";
  }
}

void ledOn(){
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
}

void first(){
  analogWrite(RED, 255 - 63.75*4);
  analogWrite(GREEN, 255 - 63.75*4);
  analogWrite(BLUE, 255 - 63.75*4);
}

void second(){
  analogWrite(RED, 255 - 63.75*3);
  analogWrite(GREEN, 255 - 63.75*3);
  analogWrite(BLUE, 255 - 63.75*3);
}

void thrid(){
  analogWrite(RED, 255 - 63.75*2);
  analogWrite(GREEN, 255 - 63.75*2);
  analogWrite(BLUE, 255 - 63.75*2);
}

void fourth(){
  analogWrite(RED, 255 - 63.75);
  analogWrite(GREEN, 255 - 63.75);
  analogWrite(BLUE, 255 - 63.75);
}

void fifth(){
  analogWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);
}

void ledOff(){
  analogWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);
}

