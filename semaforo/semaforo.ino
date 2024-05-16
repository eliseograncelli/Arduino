int ledR = 2, ledA = 3, ledV = 4;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledV, OUTPUT);
  digitalWrite(ledR, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledV, LOW);
}

void loop() {
  digitalWrite(ledR,HIGH);
  delay(5000);
  digitalWrite(ledR,LOW);
  digitalWrite(ledA, HIGH);
  delay(500);
  digitalWrite(ledA, LOW);
  digitalWrite(ledV,HIGH);
  delay(5000);
  digitalWrite(ledA, HIGH);
  delay(500);
  digitalWrite(ledV, LOW);
  delay(500);
  digitalWrite(ledA, LOW);
}
