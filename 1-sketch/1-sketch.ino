int pushButton = D2;

void setup() {
  Serial.begin(115200);
  
  pinMode(pushButton, INPUT_PULLUP);
}

void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);

  
  //print out the state of the button:
  Serial.println(buttonState);
  delay(10);   //delay between reads for stability
}
