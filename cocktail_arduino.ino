#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "YOUR-FIREBASE-HOST" // Firebase host
#define FIREBASE_AUTH "YOUR-FIREBASE-AUTH-KEY" // Firebase Auth code
#define WIFI_SSID "YOUR-WIFI-SSID" // Enter your WiFi Name
#define WIFI_PASSWORD "YOUR-WIFI-PASSWORD" // Enter your password

#define PUMP1 D1// Assuming Pump 1 is connected to digital pin D1
#define PUMP2 D2 // Assuming Pump 2 is connected to digital pin D2
#define PUMP3 D3// Assuming Pump 3 is connected to digital pin D3


void setup() {
  //Initializing serial monitor
  Serial.begin(9600);
  //declaring pins in micro controller
  pinMode(PUMP1, OUTPUT);
  pinMode(PUMP2, OUTPUT);
  pinMode(PUMP3, OUTPUT);

  //Attempting to connect to the wifi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println("Connected to WiFi.");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());//print the Local IP address in the serial monitor

  //Attempting to connect to the firebase host
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  if (Firebase.failed()) {
    Serial.print("Failed to connect to Firebase: ");
    Serial.println(Firebase.error());
  } else {
    Serial.println("Connected to Firebase.");
  
}
}
void loop() {
  // Fetch the values from Firebase
  int redValue = Firebase.getInt("/Green/Red");
  int blueValue = Firebase.getInt("/Green/Blue");
  int yellowValue = Firebase.getInt("/Green/Yellow");


  // Dispense drinks based on the values
  dispenseDrink(PUMP1, redValue);
  dispenseDrink(PUMP2, blueValue);
  dispenseDrink(PUMP3, yellowValue);

  delay(6000); // Wait 10 seconds before checking again
}

void dispenseDrink(int pumpPin, int value ) {
  if (value > 0) {
    int dispenseTime = value * 100; // Convert value to milliseconds

    digitalWrite(pumpPin, HIGH); // Turn on the pump
    delay(dispenseTime); // Keep the pump on for the calculated time
    digitalWrite(pumpPin, LOW);
    delay(5000); // Turn off the pump

    Serial.println("pump stopped.");
  }
}