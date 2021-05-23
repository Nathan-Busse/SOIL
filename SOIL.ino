#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16,2); // if error get address from i2c scanner
#define SensorPin A0
float sensorValue = 0;

void setup() {
 Serial.begin(9600);
   
  lcd.init();
  lcd.clear();         
  lcd.backlight();

}

void loop() {
  lcd.setCursor(1, 0);
  lcd.print("Soil Moisture");
  lcd.setCursor(2, 2);
  //lcd.clear();
  
  // put your main code here, to run repeatedly:
 for(int i = 0; i<= 100; i++)
 {
  sensorValue = sensorValue + analogRead(SensorPin);
  
  delay(1);
 }
 sensorValue = sensorValue/100.0;
 lcd.setCursor(5,4); 
 Serial.println(sensorValue);
 lcd.print(sensorValue);
 delay(30);
}
  
 
