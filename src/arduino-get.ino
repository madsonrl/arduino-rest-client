#include <Ethernet.h>
#include <SPI.h>
#include "RestClient.h"

RestClient client = RestClient("10.0.0.142");

//Setup
void setup() {
  Serial.begin(9600);
  // Connect via DHCP
  Serial.println("connect to network");
  //client.dhcp();

  // Can still fall back to manual config:
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  //the IP address for the shield:
  byte ip[] = { 10, 0, 0, 88 };
  Ethernet.begin(mac,ip);

  Serial.println("Setup!");
}

String response;
void loop(){
  response = "";
  int statusCode = client.get("/atuador/return.mwh", &response);
  Serial.print("Status code from server: ");
  Serial.println(statusCode);
  Serial.print("Response body from server: ");
  Serial.println(response);
  delay(1000);
}
