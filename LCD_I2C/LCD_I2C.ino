#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
int LM = A0;// chân analog kết nối cảm biến LM35
hd44780_I2Cexp lcd;

String a = "Nhiet do";
void setup()
{ 
 Serial.begin(9600);
 lcd.begin(16,2);
 lcd.print(a);
}
void loop()
{
  int reading = analogRead(LM);// đọc giá trị từ cảm biến
  float voltage = reading*5.0/1024.0;// tính ra giá trị hiệu điện thế
  float temp = voltage*100.0;// tính ra giá trị độ C
  // cứ mỗi 10mV = 1 độ C
  lcd.setCursor(0,1);
  lcd.print(temp);
  delay(100);
}
