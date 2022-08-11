int pinInput = D1;
int val = 0;
void setup() {
  Serial.begin(9600);
  pinMode(pinInput, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinInput), limitSwitch, FALLING);
}

void loop() {

  val = digitalRead(pinInput);
  Serial.println(val);

  delay(5000);

}

ICACHE_RAM_ATTR void limitSwitch(){
  val = digitalRead(pinInput);
  Serial.println(val);
}
