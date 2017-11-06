int Pin = 6;

void setup() {
  Serial.begin(9600);
}

char mSymbols[30][6] = {
  ".-", //A
  "-...", //B
  "-.-.", //C
  "-..", //D
  ".", //E
  "..-.", //F
  "--.", //G
  "....", //H
  "..", //I
  ".---", //J
  "-.-", //K
  ".-..", //L
  "--", //M
  "-.", //N
  "---", //O
  ".--.", //P
  "--.-", //Q
  ".-.", //R
  "...", //S
  "-", //T
  "..-", //U
  "...-", //V
  ".--", //W
  "-..-", //X
  "-.--", //Y
  "--..", //Z
};

long t1 = 0, t2 = 0;
long timeAlb[6];
char Msg[20];

void setDelay(char *mNums) {
  for (int i = 0; i < strlen(mNums); i++) {
    if (mNums[i] == '.') {
      digitalWrite(Pin, HIGH);
      delay(15);
      digitalWrite(Pin, LOW);
      Serial.print(".");
    } 
    if (mNums[i] == '-') {
      digitalWrite(Pin, HIGH);
      delay(30);
      digitalWrite(Pin, LOW);
      Serial.print("-");
    }
  }
  digitalWrite(Pin, HIGH);
  delay(50);
  digitalWrite(Pin, LOW);
  Serial.println();
}

void encode(char c) {
  Serial.print("I recieved: ");
  Serial.println(c);
  //65 - 90 97-122
  setDelay(mSymbols[(int)c - 65]);
  
}

char equalsMsg(char *Alb) {
  for (int i = 0; i < 26; i++) {
    int count = 0;
    for (count; mSymbols[i][count] == Alb[count]; count++)
    if ((count == strlen(mSymbols[i]) - 1) && (count == strlen(Alb) - 1)) { 
      //Serial.println((char)( i + 65));
      return (char)( i + 65);
    }
  }
  return '?';
}

char decodeMsg(long *timeM) {
  char result[6] = "";
  for(int i = 0; timeM[i] != 0 || i < 6; i++){
    if (timeM[i] > 9 && timeM[i] < 25)
      result[i] = '.';
    if (timeM[i] > 25 && timeM[i] < 45)
      result[i] = '-';
    if (timeM[i] > 45 && timeM[i] < 55)
      return equalsMsg(result);
  }
}

void writing() {
  int mByte;
  pinMode(Pin, OUTPUT);
  while (Serial.available() > 0) {
    mByte = Serial.read();
    encode((char)mByte);
  }
  Serial.println("End.");
  digitalWrite(Pin, HIGH);
  delay(60);
  digitalWrite(Pin, LOW);
}

void reading() {
  pinMode(Pin, INPUT);
  for (int i = 0; i < 6; i++)
    timeAlb[i] = 0;
  for (int i = 0; t2 < 48;){
    if (digitalRead(Pin) == 1) {
      t1 = millis();
    } else {
      return;
    }
    while (digitalRead(Pin) == 1) {
    }
    if (t1 != 0) {
      timeAlb[i] = millis() - t1;
      t2 = millis() - t1;
      Serial.print("t2 = ");
      Serial.println(timeAlb[i]);
      i++;
    }
  }
  t2 = millis() - t1;
  if (t2 < 58 && strlen(Msg) < 20) {
    Msg[strlen(Msg)] = decodeMsg(timeAlb);
  } else {
    Serial.println(Msg);
    for(int i = 0; i < 20; i++)
      Msg[i] = NULL;
  }
  t1 = t2 = 0;
}
  
void loop() {
  bool Mode = false;
  if (Serial.available() > 0) {
    writing();
    Mode = true;
  } else {
    if (!Mode) {
      reading();
    }
  }
}
