#include <EnableInterrupt.h>

#define encoderX1 2
#define encoderX2 3
#define encoderY1 4
#define encoderY2 5

volatile int currentXPosition = 0;
volatile int currentYPosition = 0;

void setup()
{
  Serial.begin(9600); //set baud rate
  pinMode(encoderX1, INPUT_PULLUP);
  pinMode(encoderX2, INPUT_PULLUP);
  enableInterrupt(2, handleEncoderX1, CHANGE);
  enableInterrupt(3, handleEncoderX2, CHANGE);
  enableInterrupt(4, handleEncoderY1, CHANGE);
  enableInterrupt(5, handleEncoderY2, CHANGE);
}

void loop()
{
  Serial.print("X: ");
  Serial.print(currentXPosition);
  Serial.print("   Y: ");
  Serial.println(currentYPosition);
  delay(10);
}

void handleEncoderX1()
{
  if(digitalRead(encoderX1) != digitalRead(encoderX2)) {
    currentXPosition++;
  }
  else{
    currentXPosition--;
  }
}

void handleEncoderX2()
{
  if(digitalRead(encoderX1) == digitalRead(encoderX2)) {
    currentXPosition++;
  }
  else{
    currentXPosition--;
  }
}

void handleEncoderY1()
{
  if(digitalRead(encoderY1) != digitalRead(encoderY2)) {
    currentYPosition++;
  }
  else{
    currentYPosition--;
  }
}

void handleEncoderY2()
{
  if(digitalRead(encoderY1) == digitalRead(encoderY2)) {
    currentYPosition++;
  }
  else{
    currentYPosition--;
  }
}
