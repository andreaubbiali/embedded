// utilizzo di const che almeno me l'alloca in un posto diverso della memoria e non occupa spazio. Dato che questo dato dovrebbe cambiare quasi mai.
// oppure utilizzare
// #define PULSANTE = D2;
const int pulsante = D2;
int contatore = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pulsante, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(pulsante) == LOW){
    contatore++;
    Serial.println("premuto:");
    Serial.println(contatore);

    // per eliminare problema rimbalzo. con 100 devi fare pressione stra veloce.
    delay(100);
    
    // while toglie problema della doppia lettura ma non problema del rimbalzo (tipico degli interruttori)
    /*
    while(digitalRead(pulsante) == LOW){
      // do nothing
      // senza questo conta più volte anche un solo click
    }
    PROBLEMA DEL RESET CON QUESTO WHILE
    se tengo schiacciato il pulsante esce un soft reset.
    watchdog dell'esp, un pezzo di firmware che se non viene stimolato periodicamnete resetta.
    questo è ciò che avviene 
    WDT -> WATCHDOG
    loop vuoto è un loop che non fa nulla, consuma il processore senza mollare il controllo.
    L'unico modo per non farlo avvenire è l'utilizzo di un delay all'interno del while il quale va a stimolare il whatchdog.
    
    */
  }
}

// collegare 
// gnd-gnd
// sw-d2
// non ho messo il 3v perchè ho impostato input_pullup
