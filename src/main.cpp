// If you want to run in WOKWi
// change pin and wifi
#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Bounce2.h>
//#include "traffic.h"

#define red 27
#define yellow 26
#define green 25
#define ldr 32
#define button 33

#define light <แสดงมันมืด มีค่าเท่าไหร่>

int state = 1;
int count = 0;
Bounce debouncer = Bounce();

void Connect_Wifi();

void setup()
{
  Serial.begin(115200);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(ldr, INPUT);
  debouncer.attach(button, INPUT_PULLUP);
  debouncer.interval(25);
  //Connect_Wifi();

  delay(200);
  // start LED with GREEN and POST to database
  digitalWrite(green, HIGH);
  //POST_traffic("green");
}

void loop()
{
  // *** write your code here ***
  // Your can change everything that you want
  debouncer.update();
  if (state == 1)
  {
    // while led GREEN
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH );
    
    while(!debouncer.fell()) debouncer.update();

    state =2;

  }
  else if (state == 2)
  {
    Serial.println("State2");
    digitalWrite(green,LOW);
    digitalWrite(yellow,HIGH);
    delay(8000);
    state = 3;

  }
  else if (state == 3)
  {
    // while led RED
    Serial.println("State3");
    digitalWrite(yellow, LOW);
    digitalWrite(red,HIGH);
    delay(5000);
    while (true){
      if(analogRead(ldr)<2000)
        state = 1;
        break;
    }
  }
}

void Connect_Wifi()
{
  const char *ssid = "Your Wifi Name";
  const char *password = "Your Wifi Password";
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("OK! IP=");
  Serial.println(WiFi.localIP());
  Serial.println("----------------------------------");
}