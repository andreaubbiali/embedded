int pinInput = D2;
int val = 0;
void setup() {
  Serial.begin(115200);
  pinMode(pinInput, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinInput), limitSwitch, FALLING);
}

void loop() {

  val = digitalRead(pinInput);
  Serial.println(val);

  delay(200);

}

ICACHE_RAM_ATTR void limitSwitch(){
  Serial.println("FINE CORSA CLICCATO");
}

