#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

// Dirección y pines de la pantalla LCD
// Argumentos: I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7); 


void setup() {
  lcd.begin(16,2);
  // argumento: 3 = pin del contraste de la retroiluminación
  lcd.setBacklightPin(3,POSITIVE);

  lcd.setBacklight(HIGH);   // retroiluminación ON
  lcd.print(" lurailabs.com ");
  lcd.setCursor(0, 1);      // cursor a caracter 0 de línea 1 (la segunda)
  lcd.print("probando la pantalla LCD");
  delay(3000);
  lcd.clear();              // borrar pantalla
  delay(3000);
  lcd.setBacklight(LOW);    // retroiluminación OFF

}

void loop() {


}
