#include <FirebaseArduino.h>

#include <ESP8266WiFi.h>

#define FIREBASE_HOST "fir-auth-6ebf2.firebaseio.com"
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "12345"


void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.println(". ");
  }
  Serial.println("\n");
  Serial.println("Connected To WiFi!!\n");
  Firebase.begin(FIREBASE_HOST);
}
//LM35: facing flat end towards you, r8 to left: vcc, A0, gnd

void loop() {
  int analog = analogRead(17);
  float celsius = analog * 0.322265625;
  Serial.print(celsius);
  Serial.println(" Deg celsius");
  Firebase.setFloat("Deg Celsius: ",celsius);
  delay(500);
}


