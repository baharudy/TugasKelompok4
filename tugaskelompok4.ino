#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,9,10,11,12);
int LM35 = A0;
int nilaiLM35 = 0;
int LED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("KELOMPOK 4");
  lcd.setCursor(1,1);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SUHU RUANG");
}

void loop() {
  nilaiLM35 = analogRead(LM35);
  nilaiLM35 = nilaiLM35 * 0.488;
  lcd.setCursor(11,0);
  lcd.print(nilaiLM35);
  Serial.print(nilaiLM35);
  delay(300);
  
  if (nilaiLM35 > 55)
  {
    digitalWrite(LED, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SUHU RUANG");
    lcd.setCursor(0,1);
    lcd.print("PENDINGIN NYALA");
  }
  else if (nilaiLM35 < 35)
  {
   digitalWrite(LED, LOW);
    lcd.clear();
    lcd.print("SUHU RUANG");
    lcd.setCursor(0,1);
    lcd.print("PENDINGIN MATI"); 
  }  
}
