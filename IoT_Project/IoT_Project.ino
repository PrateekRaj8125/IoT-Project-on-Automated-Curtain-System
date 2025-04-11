#include <WiFi.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>

// Wi-Fi Credentials
#define WIFI_SSID "Wifi ka bill tera baap bharega"
#define WIFI_PASS "12345678"

// Sinric Pro Credentials
#define APP_KEY "e0e34797-5836-4310-87b3-77e501201809"         // Get from Sinric Pro dashboard
#define APP_SECRET "5f8f0eb9-17ce-4f3c-a34a-1fc4d2af96bb-af2a3ade-4e6f-4b44-9967-bdc8f1f1db8b"   // Get from Sinric Pro dashboard
#define DEVICE_ID_OPEN "67f4e1b58ed485694c0dfffc"  // Device ID for Open Curtain command
#define DEVICE_ID_CLOSE "67f4e3df947cbabd20f2ac35"  // Device ID for Close Curtain command
#define DEVICE_ID_STOP "67f4e426947cbabd20f2ad13"  // Device ID for Motor Off command

// Motor Driver Pins
#define IN1 26  // L293D IN1 connected to ESP32 GPIO27
#define IN2 27  // L293D IN2 connected to ESP32 GPIO26
#define ENA 14  // L293D ENA (PWM) connected to ESP32 GPIO14

bool motorStateOpen = false;   // Motor state for opening curtain
bool motorStateClose = false;  // Motor state for closing curtain
bool motorStateStop = false;   // Motor state for stopping the motor

// Callback function for Open Curtain command
bool onOpenCurtain(const String &deviceId, bool &state) {
  if (deviceId == DEVICE_ID_OPEN) {
    motorStateOpen = state;

    if (motorStateOpen) {
      Serial.println("Opening Curtain - Clockwise rotation");
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 200);  // Adjust speed (0-255)
    } else {
      Serial.println("Stopping Motor");
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }
    return true;
  }
  return false;
}

// Callback function for Close Curtain command
bool onCloseCurtain(const String &deviceId, bool &state) {
  if (deviceId == DEVICE_ID_CLOSE) {
    motorStateClose = state;

    if (motorStateClose) {
      Serial.println("Closing Curtain - Counterclockwise rotation");
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, 200);  // Adjust speed (0-255)
    } else {
      Serial.println("Stopping Motor");
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }
    return true;
  }
  return false;
}

// Callback function for Motor Off command
bool onMotorOff(const String &deviceId, bool &state) {
  if (deviceId == DEVICE_ID_STOP) {
    motorStateStop = state;

    if (motorStateStop) {
      Serial.println("Motor Stopped");
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }
    return true;
  }
  return false;
}

void setup() {
  Serial.begin(115200);

  // Initialize Wi-Fi connection
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi");

  // Initialize Motor Driver Pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Stop the motor initially
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Initialize Sinric Pro devices for Open, Close, and Stop commands
  SinricProSwitch &openCurtain = SinricPro[DEVICE_ID_OPEN];
  openCurtain.onPowerState(onOpenCurtain);

  SinricProSwitch &closeCurtain = SinricPro[DEVICE_ID_CLOSE];
  closeCurtain.onPowerState(onCloseCurtain);

  SinricProSwitch &stopMotor = SinricPro[DEVICE_ID_STOP];
  stopMotor.onPowerState(onMotorOff);

  // Start Sinric Pro service
  SinricPro.begin(APP_KEY, APP_SECRET);
}

void loop() {
  SinricPro.handle(); // Handle incoming commands from Sinric Pro
}
