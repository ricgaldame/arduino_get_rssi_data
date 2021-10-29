#include <ESP8266WiFi.h>
int number_samples = 0;
void setup(){
  //Begin the bauds for serial port
  Serial.begin(115200);
  //Remove garbage
  Serial.println(""); 
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  delay(100);
}

void loop() {
  //ESP has tendency to store old SSID and PASSword and tries to connect
  WiFi.disconnect();  
  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();

  if(number_samples <= 20){
    if(n > 0){
      for (int i = 0; i < n; ++i){
        String wifi = WiFi.SSID(i);
        if(wifi.indexOf("esp_ap") >= 0){
          Serial.print(number_samples);
          Serial.print(" | ");
          //WIFI ID
          Serial.print(wifi); 
          //MAC address
          //Serial.print(WiFi.BSSIDstr(i));
          Serial.print(" | ");
          //Signal Strength
          Serial.println(WiFi.RSSI(i));
        }
        delay(10);
      }
      number_samples++;
    }
    Serial.println("");
  }
  Wait a bit before starting New scanning again
  delay(1000);
}
