#include <ESP8266WiFi.h>

const char* ssid     = "NEWINTI-Student";
const char* password = "iicp@penang";

WiFiClient client;
 
void setup() 
{
       Serial.begin(9600);
       delay(10);
               
       Serial.println("Connecting to ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, password); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 
      Serial.println(WiFi.localIP());
}
 
void loop() 
{      
  delay(1000);
}

