# FireWatch: Early Wildfire Detection System

**FireWatch** is a wireless device designed for the early detection of wildfires using specialized sensors. It operates independently of traditional communication networks, making it ideal for deployment in remote forested areas. By providing timely alerts, FireWatch helps minimize damage to ecosystems, human life, wildlife, and the economy.

---

## Features

- **Wireless Data Transmission**: Uses a 433 MHz RF communication module to transmit sensor readings.
- **Multisensor Monitoring**:
  - **Flame Detection**: Detects open flames in the vicinity.
  - **Gas Monitoring**: Measures gas levels indicative of smoke or combustion.
  - **Temperature Sensing**: Monitors ambient temperature for abnormal increases.
- **Power Efficiency**: Designed for long-term operation in remote locations.
- **Real-Time Alerts**: Sends sensor data wirelessly to a monitoring station equipped with a receiver and display.

---

## Components

### Transmitter Module
1. **DHT11**: Temperature and humidity sensor.
2. **Gas Sensor**: Detects gases like CO and CO₂ associated with combustion (e.g., MQ-2).
3. **Flame Sensor**: Detects the presence of flames.
4. **433 MHz RF Transmitter**: Wireless data transmission module (FS1000A).
5. **Arduino**: Microcontroller for processing sensor data.
6. Power source (e.g., battery pack).

### Receiver Module
1. **433 MHz RF Receiver**: Wireless data reception module (MX-RM-5V).
2. **LCD Display**: 16x2 screen with I2C interface for displaying received data.
3. **Arduino**: Microcontroller for processing and displaying received data.
4. Power source.

---

## Circuit Connections

### Transmitter Module
- **DHT11 Sensor**:
  - Data Pin → Digital Pin 2.
- **Gas Sensor**:
  - Analog Output → Analog Pin A1.
  - Digital Output → Digital Pin 4.
- **Flame Sensor**:
  - Analog Output → Analog Pin A0.
- **433 MHz RF Transmitter**:
  - Data Pin → Digital Pin 12.
- Power all components using an external power source or Arduino's onboard power.

### Receiver Module
- **433 MHz RF Receiver**:
  - Data Pin → Digital Pin 2.
- **LCD Display**:
  - SDA → Arduino SDA.
  - SCL → Arduino SCL.
- Power both the receiver and the display using an external power source or Arduino's onboard power.

---

## Code Files

1. **Transmitter Code**: `FireWatch_Transmitter.ino`  
   Collects sensor data and sends it wirelessly.

2. **Receiver Code**: `FireWatch_Receiver.ino`  
   Receives transmitted data and displays it on an LCD.

---

## How to Use

1. **Setup the Transmitter**:
   - Connect the sensors and transmitter module as per the circuit diagram.
   - Upload the `FireWatch_Transmitter.ino` code to the Arduino.
   - Deploy the device in the field with a power source.

2. **Setup the Receiver**:
   - Connect the receiver and LCD display as per the circuit diagram.
   - Upload the `FireWatch_Receiver.ino` code to the Arduino.
   - Power the receiver and keep it within the transmission range.

---

## Applications

- **Wildfire Prevention**: Early detection of potential fires in remote areas.
- **Environmental Monitoring**: Tracks changes in environmental parameters like temperature and gas levels.
- **Disaster Management**: Alerts authorities to potential dangers, enabling faster response.

---

## Folder Structure



---

## Dependencies

- **Libraries for Transmitter Module**:
  - [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)
  - [iArduino RF433 Transmitter](https://github.com/iArduino/RF433)

- **Libraries for Receiver Module**:
  - [LiquidCrystal_I2C Library](https://github.com/johnrickman/LiquidCrystal_I2C)
  - [iArduino RF433 Receiver](https://github.com/iArduino/RF433)

---

## Future Enhancements

1. **Solar-Powered Operation**: Integrate solar panels for extended deployment in remote areas.
2. **Data Storage**: Add an SD card module for logging sensor readings.
3. **Network Integration**: Enable connectivity to IoT platforms for centralized monitoring.
4. **Improved Detection**: Use more advanced sensors for better accuracy and sensitivity.

---

## License

This project is licensed under the [MIT License](LICENSE).

---

## Contributors

- **[Your Name]** – Developer
- Open for contributions! Feel free to submit pull requests or suggest improvements.
