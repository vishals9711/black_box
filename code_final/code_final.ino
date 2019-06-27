#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h> 

TinyGPSPlus gps;  // The TinyGPS++ object

SoftwareSerial ss(4, 5); // The serial connection to the GPS device
///////////////////////////////////////////////////////
const char* ssid = "Vishal Laptop";
const char* password = "gec12345";
//////////////////////////////////// /*Variables Defination */
float latitude , longitude;
int year , month , date, hour , minute , second;
String date_str , time_str , lat_str , lng_str,reg;
int pm,t,d,sped;

///////////////////////////////////////////////////////
#define ORG "68zltm"
#define DEVICE_TYPE "ESP8266"
#define DEVICE_ID "black_box"
#define TOKEN "123456789"
//////////////////////////////////////////////////////
char server[] = ORG ".messaging.internetofthings.ibmcloud.com";
char topic[] = "iot-2/evt/status/fmt/json";
char authMethod[] = "use-token-auth";
char token[] = TOKEN;
char clientId[] = "d:" ORG ":" DEVICE_TYPE ":" DEVICE_ID;
/////////////////////////////////////////////////////
WiFiClient wifiClient;
PubSubClient client1(server, 1883, NULL, wifiClient);
////////////////////////////////////////////////////

WiFiServer server1(80);
void setup()
{
  latitude=15.422370;
longitude=73.979551;
reg="GA-06-D-2608";
  Serial.begin(115200);
  ss.begin(9600);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  server1.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());

}

void loop()
{
  if (!client1.connected()) {
 Serial.print("Reconnecting client to ");
 Serial.println(server);
 while (!client1.connect(clientId, authMethod, token)) {
 Serial.print(".");
 delay(500);
 }
 Serial.println();
 }

//  while (ss.available() > 0)
//    if (gps.encode(ss.read()))
//    {
//      if (gps.location.isValid())
//      {
//        latitude = gps.location.lat();
//        lat_str = String(latitude , 6);
//        longitude = gps.location.lng();
//        lng_str = String(longitude , 6);
//        Serial.println(lng_str);
//        Serial.println(lat_str);
//      }
//
//      if (gps.date.isValid())
//      {
//        date_str = "";
//        date = gps.date.day();
//        month = gps.date.month();
//        year = gps.date.year();
//
//        if (date < 10)
//          date_str = '0';
//        date_str += String(date);
//
//        date_str += " / ";
//
//        if (month < 10)
//          date_str += '0';
//        date_str += String(month);
//
//        date_str += " / ";
//
//        if (year < 10)
//          date_str += '0';
//        date_str += String(year);
//      }
//
//      if (gps.time.isValid())
//      {
//        time_str = "";
//        hour = gps.time.hour();
//        minute = gps.time.minute();
//        second = gps.time.second();
//
//        minute = (minute + 30);
//        if (minute > 59)
//        {
//          minute = minute - 60;
//          hour = hour + 1;
//        }
//        hour = (hour + 5) ;
//        if (hour > 23)
//          hour = hour - 24;
//
//        if (hour >= 12)
//          pm = 1;
//        else
//          pm = 0;
//
//        hour = hour % 12;
//
//        if (hour < 10)
//          time_str = '0';
//        time_str += String(hour);
//
//        time_str += " : ";
//
//        if (minute < 10)
//          time_str += '0';
//        time_str += String(minute);
//
//        time_str += " : ";
//
//        if (second < 10)
//          time_str += '0';
//        time_str += String(second);
//
//        if (pm == 1)
//          time_str += " PM ";
//        else
//          time_str += " AM ";
//
//      }
//      t=gps.time.value();
//      d=gps.date.value();
//      sped=gps.speed.kmph();
//        Serial.println(time_str);
//        Serial.println(date_str);
latitude+=0.001;
longitude+=0.001;
sped=60;

        String payload = "{\"d\":{\"id\":\"2\",\"Reg\":\"GA-06-D-2608\"";
        payload += ",\"Lat\":";
 payload += latitude;
 payload += ",\"Long\":";
 payload += longitude;
// payload += ",\"Time\":";
// payload += t;
// payload += ",\"Date\":";
// payload += d;
  payload += ",\"Speed\":";
 payload += sped;
  
 payload += "}}";
 Serial.print("Sending payload: ");
 Serial.println(payload);
 if (client1.publish(topic, (char*) payload.c_str())) {
 Serial.println("Publish ok");
 } else {
 Serial.println("Publish failed");
 }
 delay(3000);
    //}
  // Check if a client has connected
  WiFiClient client = server1.available();
  if (!client)
  {
    return;
  }
 
 
 

}
