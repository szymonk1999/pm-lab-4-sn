#include <Arduino.h>
#include <LiquidCrystal.h>

int przyciskstan = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int godziny1, minuty1, sekundy1, godziny2, minuty2, sekundy2;
char czas1[16];
char czas2[16];

void setup() {
   lcd.begin(16, 2);
   pinMode(7, INPUT);
}

void loop() {

  przyciskstan = digitalRead(7);
  if (przyciskstan == HIGH) {
  sekundy2++;    
    if (sekundy2 == 60)
  {
    sekundy2 = 0;
    minuty2 ++;
     if (minuty2 == 60)
  {
    minuty2 = 0;
    godziny2 ++;

  }
  }
  }

  sekundy1++;
  
  if (sekundy1 == 60)
  {
    sekundy1 = 0;
    minuty1 ++;
     if (minuty1 == 60)
  {
    minuty1 = 0;
    godziny1 ++;

  }
  }
  lcd.setCursor(0, 0); 
    lcd.print(godziny2);
  lcd.print(":");
  lcd.print(minuty2);
  lcd.print(":");
  lcd.print(sekundy2);
  lcd.setCursor(0, 1); 
  lcd.print(godziny1);
  lcd.print(":");
  lcd.print(minuty1);
  lcd.print(":");
  lcd.print(sekundy1);
  delay(10);   // sekunda to 10ms
}
