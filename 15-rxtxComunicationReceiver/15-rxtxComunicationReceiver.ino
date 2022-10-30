/*
 Use with exercise 16 and connect GND though the two board 
 And also connect rx-tx and tx-rx
*/

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) {
    String c = Serial.readString();
    if (c == "ACCENDI"){
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (c == "SPEGNI"){
      digitalWrite(LED_BUILTIN, LOW);      
    }
  }
}