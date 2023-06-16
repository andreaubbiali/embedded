/**
* I was looking for a delay that is been deleted when an interrupt arrive
* Using this technique I can read a photoresistence only in some interval and 
*/

int pinInput = D2;
int val = 0;
void setup() {
  Serial.begin(115200);
  pinMode(pinInput, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinInput), limitSwitch, FALLING);
}

const uint interval = 10000;
uint lastPhotoresistenceRead = millis();

void loop() {


  if (millis() - lastPhotoresistenceRead > interval) {
    // read photoresistence
    lastPhotoresistenceRead = millis();
    Serial.println("READ PHOTORESISTENCE");
  }

  Serial.println("PHOTORESISTENCE NOT READED");

  // added delay only for the watchdog
  delay(100);

}

ICACHE_RAM_ATTR void limitSwitch(){
  Serial.println("FINE CORSA CLICCATO");
  
  lastPhotoresistenceRead = millis() + interval;
}

