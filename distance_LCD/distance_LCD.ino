
/*
======================================================================
  YwRobot Arduino LCM1602 IIV V1 - 16x2 LCD SCREEN + I2C
  HC-SR04 Ultrasonic Sensor
  
  Uses library: NewliquidCrystal_1.3.4  
  https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home
  
  CONNECTIONS ON ARDUINO UNO R3:

  LCD I2C CONNECTIONS: 
  
  * GND -> Ground
  * VIN -> 5V
  * SCL -> Arduino Analog Pin 5
  * SDA -> Arduino Analog Pin 4

  HC-SR04 CONNECTIONS:

  * GND  -> Ground
  * Echo -> Arduino Digital Pin 8
  * Trig -> Arduino Digital Pin 9
  * VCC  -> 5V
  
  AUTHOR: Lurai - http://lurailabs.com
  
======================================================================
*/


#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

long distancia;
long tiempo;

// Dirección y pines de la pantalla LCD
// Argumentos: I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7); 


void setup() {

  pinMode(9, OUTPUT);   //  pin de salida: pulso ultrasónico
  pinMode(8, INPUT);    //  pin de entrada: tiempo del rebote

  
  lcd.begin(16,2);      // tamaño de la pantalla 16x2
    
  lcd.setBacklightPin(3,POSITIVE);      // pin del contraste de la retroiluminación

  lcd.setBacklight(HIGH);       // retroiluminación ON
 
}

void loop() {
  
  lcd.clear();
  digitalWrite(9, LOW);               // Estabilización del sensor
  delayMicroseconds(5);
  digitalWrite(9, HIGH);              // Envío del pulso ultrasónico
  delayMicroseconds(10);
  
  tiempo    = pulseIn(8, HIGH);       // Tiempo entre el envío del pulso y la recepción del rebote
  distancia = int(0.017 * tiempo); 
  
  lcd.print( "Distance: " );
  lcd.print( distancia );
  lcd.print( " cm" );
  lcd.setCursor(2,1);
  lcd.print( "Time: " );
  lcd.print( tiempo ); 
  lcd.print( (char)0xE4 );    // µ symbol
  lcd.print("s");
  
  delay(1000);
}

