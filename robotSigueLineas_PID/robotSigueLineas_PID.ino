// Motor izquierda
int i3 = 10;
int i4 = 11; 
int enableI = 9; 
// Motor derecha
int i2 = 6; 
int i1 = 5; 
int enableD = 3; 
//sensores
int s_centro = A0;
int s_derecha = A1;
int s_izquierda = A2;
//parametros 
float  Kp = 1.0;  
float  Ki = 0.0016;         
float  Kd = 0.5;

int ult_error = 0;
int P;
int I;
int D;

int vel_base = 70;

void setup() {
  pinMode(i3, OUTPUT);
  pinMode(i4, OUTPUT);
  pinMode(enableI, OUTPUT);
  pinMode(i2, OUTPUT);
  pinMode(i1, OUTPUT);
  pinMode(enableD, OUTPUT);

  pinMode(s_centro, INPUT);
  pinMode(s_derecha, INPUT);
  pinMode(s_izquierda, INPUT);

  digitalWrite(i3, LOW);
  digitalWrite(i4, LOW);
  digitalWrite(enableI, LOW);
  digitalWrite(i2, LOW);
  digitalWrite(i1, LOW);
  digitalWrite(enableD, LOW);
}


void loop() {
  int valorC = analogRead(s_centro);
  int valorD = analogRead(s_derecha);
  int valorI = analogRead(s_izquierda);
  
  int error = calcula_error(valorD,valorC,valorI);
 
  P = error;
  I = I + error;
  D = error - ult_error;
  
  ult_error = error;
  
  int vel_controlador = P*Kp + I*Ki + D*Kd;

  int velocidad_m_derecha = vel_base - vel_controlador;
  int velocidad_m_izquierda = vel_base +  vel_controlador;
  
  int vd = constrain(velocidad_m_derecha, -70, 110);
  int vi = constrain(velocidad_m_izquierda, -70, 110);
  
  if(vd < 0) {
    digitalWrite(i3, LOW);
  	digitalWrite(i4, HIGH);
    vd = -vd;
  } else {
    digitalWrite(i3, HIGH);
  	digitalWrite(i4, LOW);
  }
  if(vi < 0) {
    digitalWrite(i2, LOW);
  	digitalWrite(i1, HIGH);
    vi = -vi;
  } else {
    digitalWrite(i2, HIGH);
  	digitalWrite(i1, LOW);
  }
  analogWrite(enableI, vd);  
  analogWrite(enableD, vi);
}


int calcula_error(int valorD,int valorC, int valorI){
  int total = valorD + valorC + valorI;
  long pos = (2000L * valorI + 1000L * valorC) / total;
  int error = 1000 - pos;
  return error;
}