#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>
const char* ssid = "Jtb";
const char* password = "zlsq1912";

void Connect_Wifi()
{
    WiFi.begin(ssid, password);
    Serial.print("connecting to Wifi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.print("OK! IP=");
    Serial.println(WiFi.localIP());
    Serial.println("-----------------------");
}   