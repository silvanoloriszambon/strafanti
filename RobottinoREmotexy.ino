/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.3.3 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.1.1 or later version;
     - for iOS 1.2.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "TANKO"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,3,0,0,0,36,0,8,30,0,
  4,48,13,2,13,60,25,34,4,48,
  74,2,13,59,24,34,2,0,41,47,
  18,8,34,26,31,31,79,78,0,79,
  70,70,0 };
  
// this structure defines all the variables of your control interface 
struct {

    // input variable
  int8_t slider_sx; // =-100..100 slider position 
  int8_t slider_dx; // =-100..100 slider position 
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 3
#define DIRA 0
#define PWMA 5
#define DIRB 2
#define PWMB 4


void setup() 
{
  RemoteXY_Init (); 
  Serial.begin(115200);  
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (DIRA, OUTPUT);
  pinMode (PWMA, OUTPUT);
  pinMode (DIRB, OUTPUT);
  pinMode (PWMB, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);

  
  
  
  if(RemoteXY.slider_dx<0){
    digitalWrite(DIRA,1);} 
    else{
      digitalWrite(DIRA,0);} 
  if(RemoteXY.slider_sx<0){
    digitalWrite(DIRB,1);}
    else{
      digitalWrite(DIRB,0);}
  
  
  analogWrite(PWMA, abs(RemoteXY.slider_dx)*10);
  Serial.println(-abs(RemoteXY.slider_dx)*10);
  analogWrite(PWMB, abs(RemoteXY.slider_sx)*10);
  Serial.print("slider: ");
  //Serial.println(abs(RemoteXY.slider_dx)/2);

}
