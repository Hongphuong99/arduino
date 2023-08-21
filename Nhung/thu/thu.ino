#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 10);  // CE, CSN
//address through which two modules communicate.
const byte address[6] = "00001";
char text[5];
String test;
int state =3;
void setup()
{
  while (!Serial);
  Serial.begin(9600);
  
  radio.begin();
  
  
  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();
  
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    radio.read(&text, sizeof(text));
    Serial.println(text);
    test = String(text);
    if(test=="on")
   state =1;
   if(test=="off")
   state =2;
   switch(state)
    {
      case 0: 
        Serial.println("chua doc duoc gia tri");
        break;
        case 1: 
        Serial.println("bat den");
        break;
        case 2:
        Serial.println("tat den"); 
        break;
    }
  }
}
