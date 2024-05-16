// PRENDE/APAGA LED CON DETECTOR DE SONIDO.
int led=2, detectD=3;
int valor=0, estado=0;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(detectD, INPUT);
  
  digitalWrite(led,LOW);

}

void loop() {
  valor=digitalRead(detectD);
  if(valor==HIGH){
    estado=digitalRead(led);
    digitalWrite(led,!estado);
    delay(200);
    }
  }
  


