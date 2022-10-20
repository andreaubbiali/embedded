int pinInput = D1;
int val = 0;
void setup() {
  Serial.begin(115200);
  pinMode(pinInput, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinInput), limitSwitch, RISING);
}

void loop() {

  val = digitalRead(pinInput);
  Serial.println(val);

  delay(5000);

}

ICACHE_RAM_ATTR void limitSwitch(){
  Serial.println("FINE CORSA CLICCATO");
}
