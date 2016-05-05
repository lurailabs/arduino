
/*
======================================================================
  YwRobot Arduino LCM1602 IIV V1 - 16x2 LCD SCREEN + I2C
  
  Uses library: NewliquidCrystal_1.3.4  
  https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home
  
  CONNECTIONS ON ARDUINO UNO R3:
  * GND -> Arduino GND
  * VIN -> Arduino 5V
  * SCL -> Arduino Analog Pin 5
  * SDA -> Arduino Analog Pin 4
  
  AUTHOR: LURAI http://lurailabs.com
  
======================================================================
*/


#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

// Dirección y pines de la pantalla LCD
// Argumentos: I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7); 


void setup() {

  // tamaño de la pantalla 16x2
  lcd.begin(16,2);
  
  // argumento: 3 = pin del contraste de la retroiluminación
  lcd.setBacklightPin(3,POSITIVE);

  lcd.setBacklight(HIGH);       // retroiluminación ON
  lcd.print(" lurailabs.com ");
  lcd.setCursor(0, 1);          // cursor a caracter 0 de línea 1 (la segunda)
  lcd.print("Probando la pan-");
  lcd.print("talla LCD. ");
  
  delay(3000);
  lcd.clear();                  // borrar pantalla
  delay(3000);
  lcd.setBacklight(LOW);        // retroiluminación OFF

}

void loop() {


}
