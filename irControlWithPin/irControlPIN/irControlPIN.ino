#include "IRremote.h"

IRrecv irrecv(2);
decode_results results;

// Пины для пульта
int ATT = 3;
int Source = 4;
int right = 5;
int left = 6;
int up = 7;
int down = 8;
int plus  = 9;
int minus = 10;

// Длительность импульса на оптопару
int pilseDelay = 80;

void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  pinMode(ATT, OUTPUT);
  pinMode(Source, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(plus , OUTPUT);
  pinMode(minus, OUTPUT);
}

void loop() 
{
  if ( irrecv.decode( &results )) 
  { 
    // Кнопка mute
    if (results.value==0xFF906F)
    {
      Serial.println("Mute is presed");
      digitalWrite(ATT, HIGH);
      delay(pilseDelay);
      digitalWrite(ATT, LOW);
      irrecv.enableIRIn();
    }
    
    // Кнопка mode
    if (results.value==0xFF8877)
    {
      Serial.println("Mode is presed");
      digitalWrite(Source, HIGH);
      delay(pilseDelay);
      digitalWrite(Source, LOW);
      irrecv.enableIRIn();
    }
    
    // Кнопка right
    if (results.value==0xFFE01F)
    {
      Serial.println("Right is presed");
      digitalWrite(right, HIGH);
      delay(pilseDelay);
      digitalWrite(right, LOW);
      irrecv.enableIRIn();
    }
    
    // Кнопка left
    if (results.value==0xFF609F)
    {
      Serial.println("Left is presed");
      digitalWrite(left, HIGH);
      delay(pilseDelay);
      digitalWrite(left, LOW);
      irrecv.enableIRIn();
    }
    
    // Кнопка band
    if (results.value==0xFF10EF)
    {
      Serial.println("Band is presed");
      digitalWrite(up, HIGH);
      delay(pilseDelay);
      digitalWrite(up, LOW);
      irrecv.enableIRIn();
    }
    
    // Кнопка eject
    if (results.value==0xFF50AF)
    {
      Serial.println("Eject is presed");
      digitalWrite(down, HIGH);
      delay(pilseDelay);
      digitalWrite(down, LOW);
      irrecv.enableIRIn();
    }

    // Кнопка +
    if (results.value==0xFF28D7)
    {
      Serial.println("+ is presed");
      digitalWrite(plus, HIGH);
      delay(pilseDelay);
      digitalWrite(plus, LOW);
      irrecv.enableIRIn();
    }

    // Кнопка -
    if (results.value==0xFFA857)
    {
      Serial.println("- is presed");
      digitalWrite(minus, HIGH);
      delay(pilseDelay);
      digitalWrite(minus, LOW);
      irrecv.enableIRIn();
    }

   irrecv.resume();   
  }
  
}

