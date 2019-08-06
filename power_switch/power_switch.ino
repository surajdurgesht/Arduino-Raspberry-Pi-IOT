#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

//Replace your wifi credentials here
const char* ssid     = "IIITDWD-Themepark lab-2";
const char* password = "lab2@2019";

//change your channel number here
unsigned long channel = 784177;

//1,2 and 3 are channel fields. You don't need to change if you are following this tutorial. However, you can modify it according to your application
unsigned int powerswitch = 2;

WiFiClient  client;


void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(powerswitch, OUTPUT);
  digitalWrite(powerswitch, LOW);
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);

}
void loop() {

  //get the last data of the fields
  int led_1 = ThingSpeak.readFloatField(channel, led1);

  if(powerswitch == 1){
    digitalWrite(powerswitch, HIGH);
    Serial.println("powerswitch is On..!");
  }
  else if(powerswitch == 0){
    digitalWrite(powerswitch, LOW);
    Serial.println("powerswitch is Off..!");
  }

    
  Serial.println(powerswitch);
  delay(5000);

}
