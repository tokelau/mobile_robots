#define PHO A0
#define PHT A1

String command, answer;

void setup() {
  Serial.begin(9600);
  pinMode(PHO, INPUT);
  pinMode(PHT, INPUT);
}

void loop() {
  while (Serial.available() > 0) {
    char s = (char) Serial.read();
    if (s != '\n')
      command += s;
    else {
      command.toLowerCase();
      //Serial.print("Recieved: ");
      //Serial.println(command);
      /*if (command == "s1") {
        Serial.print(analogRead(PHO));
      }
      if (command == "s2")
        Serial.print(analogRead(PHT));
      command = "";
    }*/
    if (command == "getVal"){
      answer = analogRead(PHO) + ' ' + analogRead(PHT);
      Serial.print(answer);
      command = "";
    }
    }
  }
}
