#include "IRremote.h"

IRrecv irrecv(2);
IRsend irsend;

decode_results results;

void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() 
{
  if ( irrecv.decode( &results )) 
  { 
    // Кнопка mute
    if (results.value==0xFF906F)
    {
      Serial.println("Mute is presed");
      irsend.sendJVC(0x440E054F, 32, 0);
      delayMicroseconds(75);
      irsend.sendJVC(0x440E054F, 32, 1);
      delayMicroseconds(75);
      irsend.sendJVC(0x440E054F, 32, 1);
//      irsend.sendSony(0x440E054F, 12);
      
      delay(50);
      irrecv.enableIRIn();
    }
    
    // Кнопка mode
    if (results.value==0xFF8877)
    {
      Serial.println("Mode is presed");
      irsend.sendJVC(0x440E85CF, 64, 1);
      delay(50);
      irrecv.enableIRIn();
    }
    
    // Кнопка right
    if (results.value==0xFFE01F)
    {
      Serial.println("Right is presed");
      irsend.sendJVC(0x440E3D77, 64, 1);
      delay(50);
      irrecv.enableIRIn();
    }
    
    // Кнопка left
    if (results.value==0xFF609F)
    {
      Serial.println("Left is presed");
      irsend.sendJVC(0x440EBDF7, 64, 1);
      delay(50);
      irrecv.enableIRIn();
    }
    
    // Кнопка band
    if (results.value==0xFF10EF)
    {
      Serial.println("Band is presed");
      irsend.sendJVC(0x440E5D17, 64, 1);
      delay(50);
      irrecv.enableIRIn();
    }
    
    // Кнопка eject
    if (results.value==0xFF50AF)
    {
      Serial.println("Eject is presed");
      irsend.sendJVC(0xA5CC887E, 256, 1);
      irsend.sendJVC(0xFFFFFFFF, 64, 1);
      delay(50);
      irrecv.enableIRIn();
    }

    // Кнопка +
    if (results.value==0xFF28D7)
    {
      Serial.println("+ is presed");
      irsend.sendJVC(0x440E450F, 64, 1);
      delay(50);
      irrecv.enableIRIn();
    }

    // Кнопка -
    if (results.value==0xFFA857)
    {
      Serial.println("- is presed");
      irsend.sendJVC(0x440EC58F, 32, 0);
      delay(50);
      irrecv.enableIRIn();
    }

   irrecv.resume();   
  }
  
}

