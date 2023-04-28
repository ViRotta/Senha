#include<Servo.h>
#include <LiquidCrystal.h>
#define SERVO 6 // Porta Digital 6 PWM

Servo s; // Variável Servo
int pos;
int sensor = A0;
int valor = 0;
int buzzer = 10;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
long int dado;
int controle = 0;

//-------------------------------------------
void setup() {
  Serial.begin (9600); //baud rate
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  
  s.attach(SERVO);
  s.write(0); // Inicia motor posição zero


}
//------------------------------------
void tela() {
  lcd.setCursor(5, 0);
  lcd.print("Oie");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print ("Entre com a senha: _ _ _ _");

}

//--------------------------------------
void loop() {
  valor = analogRead(sensor);
  if (valor > 400) {
    if (controle == 0) {
      tela();
      controle = 1;
    }
    //  for (lcd.diplay()) {
    if (Serial.available() > 1) {
      Serial.println(dado);
      dado = Serial.parseInt();
      lcd.setCursor(8, 0);
      lcd.print(dado);
      delay(3000);
      lcd.clear();

    }

    if (dado == 1234) {
      lcd.clear();
      lcd.print("Acesso autorizado");
      for (pos = 0; pos < 90; pos++)
      {
        s.write(pos);
        delay(15);
      }
      delay(1000);
      for (pos = 90; pos >= 0; pos--)
      {
        s.write(pos);
        delay(15);
      }
      delay( 2000);
      Serial.flush();
    }


    if (dado != 0 && dado != 1234) {
      controle = 0 ;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Senha incorreta");
      tone(buzzer, 1500);
      delay(1000);
      noTone(buzzer);
      lcd.clear();
      Serial.flush();
    }

    dado = 0;
    delay(2000);
  }
}
