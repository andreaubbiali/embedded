/*
 Use with exercise 16 and connect GND though the two board 
 And also connect rx-tx and tx-rx
*/


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("ACCENDI");
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW); 
  Serial.print("SPEGNI");
  delay(2000);
}