//PWM DEI POVERI
#define LED D1
/*
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  
  digitalWrite(LED, HIGH);
  delay(1000);          
  digitalWrite(LED, LOW);
  delay(1000); 
}
*/

// PWM COME SI USA SOLITAMENTE
void setup() {
  
  pinMode(LED, OUTPUT);
  //analogWrite(LED, 110);
}

int num = 0;
void loop() {
  
  delay(10);
  analogWrite(LED, num++); // in realtà emette una PWM non un segnale continuo
  if (num == 255){
    num = 0;
  }
}
