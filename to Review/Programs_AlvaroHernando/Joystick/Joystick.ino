/*********************************************************************
**  Device: Joystick                                                **
**  File:   EF_Joystick_Test.c                                      **
**								    **
**  Created by ElecFreaks Robi.W /10 June 2011                      **
**                                                                  **
**  Description:                                                    **
**  This file is a sample code for your reference.                  **
**                                                                  **
**  Copyright (C) 2011 ElecFreaks Corp.                     	    **
*********************************************************************/
 
 
#define BUTTON_PIN      10
#define LED_PIN         13
#define X_PIN           A0
#define Y_PIN           A1 

 
int FirstShotX , FirstShotY;
int sensorValue;
 
void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, 1);
 
  Serial.begin(19200); 
  FirstShotX = 0;
  FirstShotY = 0;
 
}
 
void loop(){
  if(digitalRead(BUTTON_PIN) == 0) {
    Serial.println("--------> Button KEY");
    digitalWrite(LED_PIN, HIGH);
  } else digitalWrite(LED_PIN, LOW);

  sensorValue = analogRead(X_PIN);
  if(FirstShotX == 0) {  
    FirstShotX = sensorValue;
    Serial.print("FirstShotX = ");
    Serial.println(FirstShotX);
  }
 
  Serial.print("X = ");
  Serial.println(sensorValue - FirstShotX);
 
  sensorValue = analogRead(Y_PIN);
  if(FirstShotY == 0) {  
    FirstShotY = sensorValue;
    Serial.print("FirstShotY = ");
    Serial.println(FirstShotY);
  }
  Serial.print("Y = ");
  Serial.println(sensorValue - FirstShotY);
 
  delay(200);
}
