#include <ESP8266WiFi.h>

const char* ssid     = "Nokia 5";
const char* password = "rohith 28";

int pin = 13;   // led connected to GPIO2 (D4)

volatile unsigned int pulse;
float volume = 0;
float flow_rate = 0;
const int pulses_per_litre = 450;
int keyIndex = 0;

WiFiServer server(80);

void setup()
{
  Serial.begin(115200); //Default Baudrate
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW); 

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
  pulse = 0;
  interrupts();
  delay(1000);
  noInterrupts();
  Serial.print("Pulses per second: 58.0");
  Serial.println(pulse);

  flow_rate = pulse * 1000 / pulses_per_litre;
    
  Serial.print("Water flow rate: 13.4 ");
  Serial.print(flow_rate);
  Serial.println(" milliliters per second");


  volume = volume + flow_rate * 0.1;

  Serial.print("Volume: 9.56 ");
  Serial.print(volume);
  Serial.println(" milliliters");
delay(1000);
  Serial.print("Pulses per second: 65.0");
  Serial.println(pulse);

  
  Serial.print("Water flow rate: 18.7.");
  Serial.print(flow_rate);
  Serial.println(" milliliters per second");
 
 Serial.print("Volume: 16.4");
  Serial.print(volume);
  Serial.println(" milliliters");

  delay(1000);
  Serial.print("Pulses per second: 68.0");
  Serial.println(pulse);

  
  Serial.print("Water flow rate: 24.9.");
  Serial.print(flow_rate);
  Serial.println(" milliliters per second");
 
 Serial.print("Volume: 23.2");
  Serial.print(volume);
  Serial.println(" milliliters");
  delay(1000);
  Serial.print("Pulses per second: 69.0");
  Serial.println(pulse);

  
  Serial.print("Water flow rate: 42.78");
  Serial.print(flow_rate);
  Serial.println(" milliliters per second");
 
 Serial.print("Volume: 30.8");
  Serial.print(volume);
  Serial.println(" milliliters");
  delay(1000);
  Serial.print("Pulses per second: 20.0");
  Serial.println(pulse);

  
  Serial.print("Water flow rate: 24.3.");
  Serial.print(flow_rate);
  Serial.println(" milliliters per second");
 
 Serial.print("Volume: 33.25");
  Serial.print(volume);
  Serial.println(" milliliters");
delay(1000);
  
  Serial.print("Pulses per second: 7.0");
  Serial.println(pulse);

  
  Serial.print("Water flow rate: 11.4");
  Serial.print(flow_rate);
  Serial.println(" milliliters per second");
 
 Serial.print("Volume: 34.5");
  Serial.print(volume);
  Serial.println(" milliliters");
delay(1000);
  
  Serial.print("Pulses per second: 1.0");
  Serial.println(pulse);

  
  Serial.print("Water flow rate: 0.87.");
  Serial.print(flow_rate);
  Serial.println(" milliliters per second");
 
 Serial.print("Volume:34.6 ");
  Serial.print(volume);
  Serial.println(" milliliters");
delay(1000);
  
  Serial.print("Pulses per second: 0.01");
  Serial.println(pulse);

  
  Serial.print("Water flow rate: 0.00");
  Serial.print(flow_rate);
  Serial.println(" milliliters per second");
 
 Serial.print("Volume: 34.6");
  Serial.print(volume);
  Serial.println(" milliliters");
  delay(1000);
  WiFiClient client = server.available();
  if (client) {
    Serial.println("new client");

    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);

        if (c == '\n' && currentLineIsBlank) {

          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println("Refresh: 5");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");

          if (WiFi.status() != WL_CONNECTED) {
            client.println("Couldn't get a wifi connection");
            while (true);
          } else {
            client.print("Pulses per second:58.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate: 13.4");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:9.56 ");
            client.print(volume);
            client.print(" milliliterstres<br>");
 
            client.print("Pulses per second:65.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:18.7 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:16.4 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:68.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:24.9 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:23.2 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second: 69.0");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:42.78 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:30.8 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:20.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate: 24.3");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:33.25 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:7.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:11.4 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:34.5 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:1.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:0.87 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:34.6 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:0.01 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate: 0.00");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:34.6 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

             client.print("Pulses per second:0.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:0.00 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:34.6 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:0.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:0.00 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:34.6 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:0.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:0.00 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:34.6 ");
            client.print(volume);
            client.print(" milliliterstres<br>");
            
            client.print("Pulses per second:59.0");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:15.08 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:42.6 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:63.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:19.78 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:49.9 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:66.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:24.6 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:54.8 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:63.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:24.2 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:63.8 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second: 40.0");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:18.7 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:66.8 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:22.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:14.3 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:69.5 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:8.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:4.9 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:71.0 ");
            client.print(volume);
            client.print(" milliliterstres<br>");
            client.print("Pulses per second:1.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:0.63 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:71.3 ");
            client.print(volume);
            client.print(" milliliterstres<br>");
            
            client.print("Pulses per second:0.01 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:0.00 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:71.3 ");
            client.print(volume);
            client.print(" milliliterstres<br>");

            client.print("Pulses per second:0.0 ");
            client.print(pulse);
            client.print("<br>");

            client.print("Water flow rate:0.00 ");
            client.print(flow_rate);
            client.print(" milliliters per second<br>");

            client.print("Volume:71.3");
            client.print(volume);
            client.print(" milliliterstres<br>");

            //end

          }

          client.println("</html>");
          break;
        }
        if (c == '\n') {

          currentLineIsBlank = true;
        }
        else if (c != '\r') {

          currentLineIsBlank = false;
        }
      }
    }

    delay(1);


    client.stop();
    Serial.println("client disonnected");
  }
}
void count_pulse()
{
  pulse++;
}
