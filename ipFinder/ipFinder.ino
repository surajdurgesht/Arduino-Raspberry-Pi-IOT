    
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid     = "IIITDWD-H3-R";
const char* password = "hostel@3r.";

//const char* ssid     = "Nokia 5";
//const char* password = "rohith28";
 

int LED = 13;   // led connected to GPIO2 (D4)

WiFiServer server(80);

 

void setup()

{

  Serial.begin(115200); //Default Baudrate

  pinMode(LED, OUTPUT);

  digitalWrite(LED, LOW);

 

  Serial.print("Connecting to the Newtork");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)

  {

    delay(500);

    Serial.print(".");

  }

  Serial.println("WiFi connected"); 

  server.begin();  // Starts the Server

  Serial.println("Server started");

 

  Serial.print("IP Address of network: "); // will IP address on Serial Monitor

  Serial.println(WiFi.localIP());

  Serial.print("Copy and paste the following URL: https://"); // Will print IP address in URL format

  Serial.print(WiFi.localIP());

  Serial.println("/");


}

 

void loop()

{

  WiFiClient client = server.available();

  if (!client)

  {

    return;

  }

  Serial.println("Waiting for new client");

  while(!client.available())

  {

    delay(1);

  }

 

  String request = client.readStringUntil('\r');

  Serial.println(request);

  client.flush();

 

  int value = LOW;

  if(request.indexOf("/LED=ON") != -1)

  {

    digitalWrite(LED, HIGH); // Turn LED ON

    value = HIGH;

  }

  if(request.indexOf("/LED=OFF") != -1)

  {

    digitalWrite(LED, LOW); // Turn LED OFF

    value = LOW;

  }

  HTTPClient http;    //Declare object of class HTTPClient
 
  String ADCData, station, getData, Link;
  //int adcvalue=analogRead(A0);  //Read Analog value of LDR
  //ADCData = String(adcvalue);   //String to interger conversion
  //station = "B";
 
  //GET Data
  //getData = "?status=" + ADCData + "&station=" + station ;  //Note "?" added at front
  Link = "https://internetcontrolledpowerswitch.000webhostapp.com/"; // + getData;
  
  http.begin(Link);     //Specify request destination
  
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload
 
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
 
  http.end();  //Close connection
  
  delay(5000);  //GET Data at every 5 seconds

//*------------------HTML Page Code---------------------*//

 

  client.println("HTTP/1.1 200 OK"); //

  client.println("Content-Type: text/html");

  client.println("");

  client.println("<!DOCTYPE HTML>");

  client.println("<html>");

 

  client.print(" CONTROL LED: ");

 

  if(value == HIGH)

  {

    client.print("ON");

  }

  else

  {

    client.print("OFF");

  }

  client.println("<br><br>");

  client.println("<a href=\"/LED=ON\"\"><button>ON</button></a>");

  client.println("<a href=\"/LED=OFF\"\"><button>OFF</button></a><br />");

  client.println("</html>");

 

  delay(1);

  Serial.println("Client disonnected");

  Serial.println("");

}
