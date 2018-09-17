#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid     = "NEWINTI-Student";
const char* password = "iicp@penang";
 
void setup() 
{
       Serial.begin(9600);
}
 
void loop() 
{      
  if(WiFi.status() != WL_CONNECTED ){
    Serial.println("Wifi not connected...");
    WiFi.begin(ssid, password); 
  } 
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  } 

  Serial.print("Connected to: "); Serial.println(WiFi.SSID());
  Serial.print("Your IP: "); Serial.println(WiFi.localIP());
  
  HTTPClient http;
  http.begin("192.168.1.100", 3000, "/"); // put your PC's IP here
  int httpCode = http.GET();
  
  if(httpCode > 0){
    Serial.printf("GET code: %d\n", httpCode);
    if(httpCode == HTTP_CODE_OK){
      String response = http.getString();
      Serial.println(response);
    }
  } else {
Serial.printf("GET failed: error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
  delay(10000);
}

