
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor


#define FIREBASE_HOST "cubes-1e3d8.firebaseio.com" //--> URL address of your Firebase Realtime Database.
#define FIREBASE_AUTH "PmNnNh2Pd86qA8hEHbk2A61wiVetmMxCqxaLnE21" //--> Your firebase database secret code.
#define WIFI_SSID "Space" // Change the name of your WIFI
#define WIFI_PASSWORD "111122220" // Change the password of your WIFI

#define DHTTYPE DHT11   // DHT 11
//#define dht_dpin D5
#define dht_dpin D3
DHT dht(dht_dpin, DHTTYPE); 
void setup(void)
{ 
  dht.begin();
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
 
  Serial.println();
  Serial.print("Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}


void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();   
    
  Serial.print("Humidity: ");  
  Serial.print(h);
  
  Serial.print("%  Temperature: ");  
  Serial.print(t);  
  Serial.println("°C ");
   
//  Firebase.setFloat ("Temp",t);
//  Firebase.setFloat ("Humidity",h);     
//  Firebase.setInt("Status", 24); 
//  Firebase.setString("Message", "hello Project Cubes");
  //Firebase.setBool("truth", false);
    
//  delay(2000);
    delay(300);
}
