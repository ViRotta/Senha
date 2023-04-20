#define led 13
long int dado;
//int controle = 0;
void setup() {
  Serial.begin (9600); //baud rate
  pinMode(led, OUTPUT);
  digitalWrite( led, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    dado = Serial.parseInt();
    Serial.println(dado);

  }
  if (dado == 1234) {

    digitalWrite( led, HIGH);
    delay(3000);
    digitalWrite(led, LOW);
  }
  if (dado != 0 && dado != 1234) {

    Serial.println("Senha incorreta");
  }
  Serial.flush();
}
