int photoResistence = A0;
int led = D1;
int sensorValue = 0;
int limitPhotoResistence = 100;
const int buttonOpenClose = D2;
int buttonState = 0;
bool isOpen = false;
bool usePhotoResistence = true;
const int buttonUsePhotoResistence = D5;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonOpenClose), buttonOpenCloseClick, HIGH);
  attachInterrupt(digitalPinToInterrupt(buttonUsePhotoResistence), buttonUsePhotoResistenceClick, HIGH);
}

void loop(){

  while(usePhotoResistence == true){
    sensorValue =  analogRead(photoResistence);
    
    if (sensorValue < limitPhotoResistence){
      openDors();
    } else {
      closeDors();
    }
    
    Serial.println(sensorValue);
    delay(1000);
  }
  
  delay(1000);
}

ICACHE_RAM_ATTR void buttonOpenCloseClick(){
  Serial.println("ENTRA buttonOpenClose");
  usePhotoResistence = false;
  if (isOpen == false) {
    openDors();
  } else {
    closeDors();
  }
}

ICACHE_RAM_ATTR void buttonUsePhotoResistenceClick(){
  Serial.println("ENTRA buttonUsePhotoResistence");
  usePhotoResistence = true;
}

void openDors(){
  digitalWrite(led, HIGH);
  isOpen = true;
}

void closeDors(){
  digitalWrite(led, LOW);
  isOpen = false;
}
