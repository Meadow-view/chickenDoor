#include <BridgeClient.h>
#include <BridgeServer.h>
#include <BridgeSSLClient.h>
#include <BridgeUdp.h>
#include <Console.h>
#include <FileIO.h>
#include <HttpClient.h>
#include <Mailbox.h>
#include <Process.h>
#include <YunClient.h>
#include <YunServer.h>


// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6

int lightPin = 0;
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int REED_PIN=53;

int leds = 0;

void setup() 
{
  //Initiate Serial communication.
  Serial.begin(9600);

  // LED setup
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  pinMode(REED_PIN, INPUT_PULLUP);
}
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
void loop() 
{
  int reading  = analogRead(lightPin);
  int threshold = 90;
  int proximity = digitalRead(REED_PIN);
  Serial.print(reading);
  Serial.print('\n');
  delay(1000); 
  Serial.print("reed switch value: ");
  Serial.print(proximity);
  Serial.print('\n');
  if (reading>threshold) 
  {
    // daylight red
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }
  else
  {
    // nightime green
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);    
  }

}
