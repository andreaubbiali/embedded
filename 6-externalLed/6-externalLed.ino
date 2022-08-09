
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(D1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D2, HIGH);
  delay(1000);                       // wait for a second
  digitalWrite(D1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(D2, LOW);
  delay(1000);                       // wait for a second
}
