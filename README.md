# IoT Project on Automated Curtain System

## Aim
To design and implement a voice-activated automatic curtain mechanism that can open and close curtains using Google Assistant voice commands via the Sinric Pro platform.

## Components Required
1. ESP32 WiFi Module Development Kit
2. L293D Motor Driver (4-channel)
3. 12V 5RPM DC Motor
4. Breadboard
5. Jumper wires(M-M & M-F)
6. Power supply (12V for the motor)
7. Smartphone with Google Assistant
8. Sinric Pro account
9. Pulley Wheel(s)

## Software Required
1. Arduino IDE with ESP32 board support
2. Sinric Pro library for Arduino
3. Google Assistant app on smartphone
4. ESP32 WiFi library
5. PWM control libraries for motor speed control


## Theory
### DC Motor Operation
DC motors convert electrical energy into mechanical energy through electromagnetic principles. The 12V 5RPM motor specified for this project offers low speed but high torque, making it ideal for curtain operations where smooth, controlled movement is essential. The direction of rotation can be controlled by reversing the polarity of the power supply to the motor.
### L293D Motor Driver
The L293D is a quadruple half-H driver IC designed to drive inductive loads such as DC motors. It can control up to four DC motors in one direction or two DC motors in both directions. Key features include:

- <ins>Operating voltage</ins>: 4.5V to 36V
- Can drive motors with current requirements up to 600mA per channel
- Protection against voltage spikes
- TTL compatible inputs

The driver serves three essential functions in our circuit:
- Protecting the ESP32 from high voltage used by the motor
- Receiving signals from ESP32 to control motor direction
- Amplifying PWM signals to control motor speed
### Sinric Pro Platform
Sinric Pro is an IoT platform that facilitates communication between smart devices and voice assistants like Google Assistant and Amazon Alexa. It provides:
- Cloud-based APIs for real-time device control
- Simple integration with various voice assistants
- Support for custom device types and actions
### Google Assistant Integration
Google Assistant serves as the user interface for our system, accepting voice commands and routing them to the appropriate device via Sinric Pro. Since its 2016 launch, it has become one of the most advanced voice assistants available, offering robust smart home control capabilities.

## Circuit Diagram
The circuit connections, based on the provided image, show:

![TinkerCAD Image of Circuit Designed](https://github.com/PrateekRaj8125/IoT-Project-on-Automated-Curtain-System/blob/main/assets/Funky%20Allis-Kieran.png?raw=true)

1. ESP32 connected to the L293D motor driver:
   - ESP32 GPIO pins connect to the IN1 and IN2 pins of the L293D for direction control
   - PWM-capable GPIO pin connects to the Enable pin for speed control
  
2. L293D motor driver connected to the DC motor:
   - Motor outputs from L293D (OUT1, OUT2) connect to the DC motor terminals
   - VCC1 (logic voltage) connects to 5V from ESP32
   - VCC2 (motor voltage) connects to external 12V power supply
   - GND pins connect to common ground

This setup allows the ESP32 to control both the direction and speed of the DC motor through the L293D driver, which handles the higher voltage and current requirements of the motor.

## Implementation
### Hardware Setup
1. Connect the ESP32 to the L293D motor driver:
   - Connect two GPIO pins (e.g., GPIO32 and GPIO33) to the IN1 and IN2 inputs
   - Connect a PWM-capable GPIO pin to the Enable input
   - Connect 3.3V to VCC1 (logic supply)
   - Connect GND to the GND pins
2. Connect the L293D to the DC motor:
   - Connect OUT1 and OUT2 to the DC motor terminals
   - Connect external 12V power supply to VCC2 (motor supply)
   - Ensure common ground between ESP32, L293D, and power supply

![Physical Image](https://github.com/PrateekRaj8125/IoT-Project-on-Automated-Curtain-System/blob/main/assets/physical_image.jpg?raw=true)

### Sinric Pro Account Setup
1. Create a Sinric Pro account
2. Add a new device (select "Switch" type for simple on/off control)
3. Note down the APP_KEY, APP_SECRET, and DEVICE_ID for use in the code

![Sinric Pro](https://github.com/PrateekRaj8125/IoT-Project-on-Automated-Curtain-System/blob/main/assets/Sinric_Pro.png?raw=true)

### Google Assistant Setup
1. Link Sinric Pro to Google Assistant
2. Discover devices through Google Home app
3. Test voice commands for device control

## Code Implementation
Use the file available in Repository name [IoT Project](https://github.com/PrateekRaj8125/IoT-Project-on-Automated-Curtain-System/tree/main/IoT_Project) for the code and implement them in the **Arduino IDE**

## Results
When properly implemented, the system enables:
1. Voice commands through Google Assistant to control curtains:
   - "*Hey Google, turn on Open Curtain*" to open curtains
   - "*Hey Google, turn on Close Curtain*" to close curtains
2. The ESP32 receives these commands through the Sinric Pro platform and controls the DC motor via the L293D driver to perform the requested action.
3. The 5RPM motor provides smooth, controlled movement suitable for curtain applications, with sufficient torque to handle the weight of standard curtains.
---

# 📜 Code of Conduct  
**IoT Project on Automated Curtain System**  

This project aims to create a voice-activated curtain system using ESP32, Sinric Pro, and Google Assistant.  
To ensure smooth collaboration, safety, and responsible usage, all contributors and users are expected to follow this Code of Conduct.  



## 1. 🤝 Respect and Collaboration
- Treat all contributors, mentors, and peers with respect.  
- Share knowledge openly and support fellow teammates.  
- Accept constructive criticism and focus on problem-solving.  
- Acknowledge others’ contributions when using or modifying their work.  



## 2. 🔌 Safety Guidelines
- Always disconnect power before making hardware changes.  
- Double-check wiring connections to prevent short circuits or damage.  
- Use insulated jumper wires and ensure proper grounding.  
- Do not exceed the rated voltage/current of components.  
- Test with caution when working with mains electricity (if integrated with home wiring).  



## 3. 🌐 Ethical Usage
- This project is intended for educational and personal smart home applications only.  
- Do not misuse the system to invade privacy or control devices without consent.  
- Respect intellectual property by giving proper credit when sharing or modifying code/designs.  
- Do not commercialize the project without permission from original contributors.  



## 4. 💻 Contribution Standards
- Write clean, well-documented code with comments for clarity.  
- Follow consistent naming conventions and coding practices.  
- Submit contributions via pull requests with clear descriptions.  
- Test your code and document changes before submission.  
- Report issues and bugs responsibly using the repository’s issue tracker.  



## 5. 🔐 Data Privacy
- Do not share your Sinric Pro API keys, secrets, or device IDs publicly.  
- Keep WiFi credentials secure and never hard-code personal data in public repositories.  
- If using Google Assistant integration, ensure that voice data remains private and secure.  



## 6. 🌍 Community Conduct
- Be inclusive—welcome beginners and experienced contributors alike.  
- Avoid offensive, discriminatory, or inappropriate behavior.  
- Help maintain a friendly environment in discussions, both online and offline.  



## 7. ✅ Accountability
- Violations of this Code of Conduct may result in restricted collaboration privileges.  
- Severe breaches (e.g., deliberate hardware damage, data misuse, or harassment) will not be tolerated.  
- Everyone is responsible for maintaining a professional and respectful project environment.  



By participating in this project, you agree to uphold this **Code of Conduct** and contribute to a safe, ethical, and collaborative learning experience.  
