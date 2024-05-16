int verde=5, amarillo=6, rojo=7;
int zumb=9, trig=3, eco=2;

void setup()
{
  Serial.begin(9600); //**********************
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(zumb, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  
  digitalWrite(rojo,LOW);
  digitalWrite(verde,LOW);
  digitalWrite(amarillo,LOW);
  
}

void loop()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  long tiempo = pulseIn(eco,HIGH);
  float distancia = (tiempo / 2.0) * 0.0343;
  //float distancia = tiempo * 0.0143;
  // 0.0343 es la velocidad del sonido [cm/microSeg]
  
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print("\n");
  delay(200);
  
  if(distancia<=50) {
    alerta3();
  }
  else if(distancia>50 && distancia <=150) {
    alerta2();
  }
  else if(distancia>150 && distancia<=300) {
    alerta();
  }
  else if(distancia>300) {
    apaga();
  }
}

void apaga() { 
  digitalWrite(verde, LOW);
  digitalWrite(amarillo, LOW);
  digitalWrite(rojo, LOW);
  delay(5);
} // APAGA LEDS

void alerta() { 
  apaga();
  digitalWrite(verde,HIGH);  
} // ALERTA CUANDO TIENE UN OBJETO A LARGA DISTANCIA

void alerta2() { 
  apaga();
  digitalWrite(amarillo,HIGH);
  tone(zumb, 500);
  delay(500);
  noTone(zumb);
  digitalWrite(amarillo,LOW);
  delay(500); 
} // ALERTA CUANDO TIENE UN OBJETO A MEDIA DISTANCIA

void alerta3() { 
  apaga();
  digitalWrite(rojo,HIGH);
  //digitalWrite(zumb,HIGH);
  tone(zumb, 1500);

  delay(200);
  noTone(zumb);
  digitalWrite(rojo,LOW);
  delay(200); 
} // ALERTA CUANDO TIENE UN OBJETO A CORTA DISTANCIA