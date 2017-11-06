#define GREEN  11
#define RED 10
#define BLUE 9
#define PR A1

bool ledOn();
bool blue();
bool red();
bool ledOff();
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
  /*while (Serial.available() == 0) {
    result = analogRead(PR);
    Serial.println(result);
  }*/
  while (Serial.available() > 0) {
    s_byte += (char)Serial.read();
    //Serial.print("Incoming byte: ");
    //Serial.println(s_byte);
  }
  if (s_byte == "On") {
    ledOn(); 
    delay(500);
    s_byte = "";
  }
  if (s_byte == "On blue") {
    ledOn(); 
    delay(500);
    s_byte = "";
  }
  if (s_byte == "On red") {
    ledOn(); 
    delay(500);
    s_byte = "";
  }
  if (s_byte == "Off") {
    ledOff();
    s_byte = "";
  }
}

bool ledOn(){
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
}

bool blue(){
  analogWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 0);
}

bool red(){
  analogWrite(RED, 0);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);
}

bool ledOff(){
  analogWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);
}

