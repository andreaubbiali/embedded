#define trigPin D2 //D2
#define echoPin D5 //D1

float duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343;

  // if (distance <= 400 && distance >=2) {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
  // }

  delay(150);
}