// const int photoResistance = D0;
// const int temperature = D1;

// void setup() {
//   Serial.begin(115200);
//   pinMode(photoResistance, OUTPUT);
//   pinMode(temperature, OUTPUT);
//   digitalWrite(photoResistance, HIGH);
//   digitalWrite(temperature, LOW);
// }

// void loop() {
//   int sensorValue = analogRead(A0);
//   Serial.println(sensorValue);
//   delay(500);
//   // if (digitalRead(photoResistance) == LOW){
//   //   digitalWrite(photoResistance, HIGH);
//   // } else {
//   //   digitalWrite(photoResistance, LOW);
//   // }
// }


int readD1;
int readD2;
int Pin_D1 = 4;
int Pin_D2 = 5;
 
void setup() {
    Serial.begin(115200);
    pinMode(Pin_D1, OUTPUT);
    pinMode(Pin_D2, OUTPUT);
  
}
 
int analogRead1() {
    digitalWrite(Pin_D1, HIGH); // Turn D1 On
    digitalWrite(Pin_D2, LOW); // Turn D2 Off
    return analogRead(0);
}
 
int analogRead2() {
    digitalWrite(Pin_D1, LOW); //  Turn D1 On
    digitalWrite(Pin_D2, HIGH); // Turn D2 Off
    return analogRead(0);
}
 
void loop() {
    readD1 = analogRead1(); // Read Analog value of first sensor
    delay(200);
    readD2 = analogRead2(); // Read Analog value of second sensor
    delay(200);
    Serial.print("sensor 1 = ");
    Serial.print(readD1);
    Serial.print(" / sensor 2 = ");
    Serial.println(readD2);
 
}