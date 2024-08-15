# ESP8266 Drink Dispenser with Firebase

This project demonstrates how to use an ESP8266 microcontroller to control a drink dispensing system based on values retrieved from Firebase. The system controls three pumps, each corresponding to a different drink (red, blue, and yellow) and dispenses drinks based on values stored in Firebase.

## Components Required

- ESP8266 WiFi Module(NodeMCU)
- 3 DC Pumps
- Relay Module (or transistor circuit for controlling pumps)
- Jumper wires
- Power supply for pumps

## Libraries Required (Included in the repository)

- ESP8266WiFi
- FirebaseArduino

## Setup Instructions

1. **Install the Arduino IDE**: Make sure you have the Arduino IDE installed on your computer.

2. **Install Required Libraries**:

3. **Configure Firebase**:
   - Create a Firebase project at [Firebase Console](https://console.firebase.google.com/).
   - Obtain your Firebase Host URL and Auth Key from the project settings.
   - Set up a real-time database and create the structure for `/Green/Red`, `/Green/Blue`, and `/Green/Yellow`.

4. **WiFi Configuration**:
   - Replace `YOUR-WIFI-SSID` and `YOUR-WIFI-PASSWORD` with your WiFi credentials.
   - Replace `YOUR-FIREBASE-HOST` and `YOUR-FIREBASE-AUTH-KEY` with your Firebase credentials.

5. **Wiring**:
   - Connect the pumps to the specified digital pins (D1, D2, D3) on the ESP8266.
   - Ensure that the pumps are connected through a relay module or a suitable transistor circuit to control the power.

## Usage

1. Upload the code to the ESP8266 using the Arduino IDE.
2. Open the Serial Monitor to view connection status and pump activity.
3. Update the values in Firebase to control the dispensing of drinks.

## License

This project is open-source and available for modification and distribution. Feel free to contribute improvements or adaptations!

