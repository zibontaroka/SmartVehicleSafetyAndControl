#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <map>

// ADXL345 Accelerometer
#define ADXL345_SDA D2 // SDA connected to D2 (GPIO4) on NodeMCU
#define ADXL345_SCL D1 // SCL connected to D1 (GPIO5) on NodeMCU
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// GY-NEO6MV2 GPS Module
SoftwareSerial gpsSerial(D5, D6); // GPS Tx to D5 (GPIO14) and Rx to D6 (GPIO12)
TinyGPSPlus gps;

// SIM800L GSM Module
#define SIM800_TX D7 // SIM800L Tx to D7 (GPIO13) on NodeMCU
#define SIM800_RX D8 // SIM800L Rx to D8 (GPIO15) on NodeMCU
SoftwareSerial sim800l(SIM800_TX, SIM800_RX);

// Phone numbers map
std::map<String, String> phoneNumbers = {
    {"Joy", "01779190716"},
    {"Anik", "01748733605"}
};

const float tiltThreshold = 45.0; // degrees
double Lat, Lag;
char Message[256], mapslink[128];

void makeCall(String phoneNumber) {
    Serial.println("Calling...");
    sim800l.println("ATD" + phoneNumber + ";");
    delay(30000); // Wait for call to connect
}

void sendMessage(String phoneNumber, char* message) {
    Serial.println("Sending message...");
    sim800l.println("AT+CMGF=1"); // Set SMS mode to text
    delay(1000);
    sim800l.print("AT+CMGS=\"");
    sim800l.print(phoneNumber);
    sim800l.println("\"");
    delay(1000);
    sim800l.println(message);
    delay(1000);
    sim800l.write(0x1A); // Send Ctrl+Z to end SMS
}

void setup() {
    Serial.begin(9600);
    gpsSerial.begin(9600);
    sim800l.begin(9600);
    Wire.begin(); // Initialize I2C bus

    // Initialize ADXL345 accelerometer
    if (!accel.begin()) {
        Serial.println("Failed to initialize ADXL345 sensor. Check wiring.");
        while (1); // Halt if initialization fails
    }
    Serial.println("ADXL345 sensor initialized.");
    accel.setDataRate(ADXL345_DATARATE_100_HZ); // Set data rate to 100 Hz
}

void loop() {
    // Read GPS data
    while (gpsSerial.available() > 0) {
        gps.encode(gpsSerial.read());
        if (gps.location.isUpdated()) {
            Lat = gps.location.lat();
            Lag = gps.location.lng();
        }
    }

    snprintf(mapslink, sizeof(mapslink), "https://www.google.com/maps?q=%.6f,%.6f", Lat, Lag);
    snprintf(Message, sizeof(Message), "Please save me. My current location is here: %s", mapslink);

    // Read accelerometer data
    sensors_event_t event;
    accel.getEvent(&event);

    // Calculate tilt angles for X-axis and Y-axis
    float angleX = asin(event.acceleration.x / 9.81) * 180 / PI;
    float angleY = asin(event.acceleration.y / 9.81) * 180 / PI;

    // Check for tilt exceeding the threshold
    if (abs(angleX) > tiltThreshold || abs(angleY) > tiltThreshold) {
        Serial.println("Accident detected!");
        for (auto const& entry : phoneNumbers) {
            sendMessage(entry.second, Message);
            delay(15000); // Wait between messages
            makeCall(entry.second);
            delay(30000); // Wait between calls
        }
    }
}