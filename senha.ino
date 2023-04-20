#define led 13
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
long int dado;
int controle = 0;

//-------------------------------------------
void setup() {
  Serial.begin (9600); //baud rate
  pinMode(led, OUTPUT);
  digitalWrite( led, LOW);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);


  //  delay(3000);
  //  lcd.clear();





  //Ligar e desligar display de acordo com os dados do sensor
  //  if (sensor == 'HIGH') {
  //    lcd.display();
  //  }else
  //  {
  //    lcd.noDisplay();
  //    delay(2000); //?
  //  }


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
    digitalWrite( led, HIGH);
    delay(3000);
    digitalWrite(led, LOW);
    lcd.print("Acesso autorizado");
    delay( 2000);
    Serial.flush();
  }


  if (dado != 0 && dado != 1234) {
    controle = 0 ;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Senha incorreta");
    lcd.clear();
    Serial.flush();
  }

  dado = 0;
  delay(2000);

}
