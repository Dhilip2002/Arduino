#include <ESP8266WiFi.h>
const char* ssid = "Your SSID";
const char* password = "Your Password";

String outputRedState = "off";
String outputGreenState = "off";
String outputYellowState = "off";

const int redLED = 2;
const int greenLED = 4;
const int yellowLED = 5;

pinMode(redLED, OUTPUT);
pinMode(greenLED, OUTPUT);
pinMode(yellowLED,OUTPUT);
digitalWrite(redLED, LOW);
digitalWrite(greenLED, LOW);
digitalWrite(yellowLED, LOW);

Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}

Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
server.begin();

WiFiClient client = server.available();

if (client) { // If a new client connects,
Serial.println("New Client."); // print a message out in the serial port
String currentLine = ""; // make a String to hold incoming data from the client
currentTime = millis();
previousTime = currentTime;
while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
currentTime = millis();
if (client.available()) { // if there's bytes to read from the client,
char c = client.read(); // read a byte, then
Serial.write(c); // print it out the serial monitor
header += c;
if (c == '\n') { // if the byte is a newline character
// if the current line is blank, you got two newline characters in a row.
// that's the end of the client HTTP request, so send a response:
if (currentLine.length() == 0) {
// HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
// and a content-type so the client knows what's coming, then a blank line:
client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println("Connection: close");
client.println();

if (header.indexOf("GET /2/on") >= 0) {
Serial.println("RED LED is on");
outputRedState = "on";
digitalWrite(redLED, HIGH);
} else if (header.indexOf("GET /2/off") >= 0) {
Serial.println("RED LED is off");
outputRedState = "off";
digitalWrite(redLED, LOW);
} else if (header.indexOf("GET /4/on") >= 0) {
Serial.println("Green LED is on");
outputGreenState = "on";
digitalWrite(greenLED, HIGH);
} else if (header.indexOf("GET /4/off") >= 0) {
Serial.println("Green LED is off");
outputGreenState = "off";
digitalWrite(greenLED, LOW);
} else if (header.indexOf("GET /5/on") >= 0) {
Serial.println("Yellow LED is on");
outputYellowState = "on";
digitalWrite(yellowLED, HIGH);
} else if (header.indexOf("GET /5/off") >= 0) {
Serial.println("Yellow LED is off");
outputYellowState = "off";
digitalWrite(yellowLED, LOW);
}

client.println("<!DOCTYPE html><html>");
client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
client.println("<link rel=\"icon\" href=\"data:,\">");

client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
client.println(".buttonRed { background-color: #ff0000; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
client.println(".buttonGreen { background-color: #00ff00; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
client.println(".buttonYellow { background-color: #feeb36; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
client.println(".buttonOff { background-color: #77878A; border: none; color: white; padding: 16px 40px; border-radius: 70%;");
client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");

client.println("<body><h1>My LED Control Server</h1>");

client.println("<p>Red LED is " + outputRedState + "</p>");

if (outputRedState=="off") {
client.println("<p><a href=\"/2/on\"><button class=\"button buttonOff\">OFF</button></a></p>");
} else {
client.println("<p><a href=\"/2/off\"><button class=\"button buttonRed\">ON</button></a></p>");
}

// Clear the header variable
header = "";
// Close the connection
client.stop();
Serial.println("Client disconnected.");
Serial.println("");
