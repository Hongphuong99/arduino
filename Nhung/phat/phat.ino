#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 10);  // CE, CSN
//address through which two modules communicate.
const byte address[6] = "00001";

int inputPin = 2;       // chọn ngõ tín hiệu vào cho PIR
int val = 0;
 
void setup()
{
  pinMode(inputPin, INPUT);
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}
 
void loop()
{
  val = digitalRead(inputPin);    // đọc giá trị đầu vào.
  if (val == HIGH)                // nếu giá trị ở mức cao.(1)
  {
   const char text1[] = "on";
    radio.write(&text1, sizeof(text1));// phat tin hieu bat den
    delay(100);
  }
  else
  {
    const char text2[] = "off";
  radio.write(&text2, sizeof(text2));// phat tin hieu bat den
  delay(100);
  }
  
}
