#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
int led1 = 7;


void setup()
{
  pinMode(led1, OUTPUT);
 
  mySerial.begin(9600);
  mySerial.println("LED uygulamasi");
}

void loop()
{
  char ch = mySerial.read();
  if (ch == '1')
  {
    digitalWrite(led1, !digitalRead(led1));
    if (digitalRead(led1) == HIGH)
    {
      mySerial.println("LED 1 yandi");
    }
    else
    {
      mySerial.println("LED 1 sondu");
    }
  }
 
  if (ch == '0')
  {
    digitalWrite(led1, LOW);
   
    mySerial.println("Tum LED'ler sondu");
  }
  if (ch == 'x')
  {
    digitalWrite(led1, HIGH);
   
    mySerial.println("Tum LED'ler yandi");
  }
}
