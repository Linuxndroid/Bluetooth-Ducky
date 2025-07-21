# 🔐 Bluetooth Ducky ESP32 -  HID Injection Tool

![Platform](https://img.shields.io/badge/platform-ESP32-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Status](https://img.shields.io/badge/status-active-brightgreen)

Bluetooth Ducky is a stealthy HID injection tool built on the ESP32 platform. It emulates a Bluetooth keyboard to silently inject keystrokes into a paired device. Perfect for red team operations, security research, and automation — all done **wirelessly**.

> ⚠️ **Disclaimer**: This project is for educational and authorized testing purposes only. Unauthorized use may violate laws. Use responsibly.

---

## ✨ Features

- ✅ Bluetooth HID (keyboard) emulation via ESP32  
- ✅ Auto-pairing support for previously connected devices  
- ✅ Ducky Script-style payloads (easily customizable)  
- ✅ Trigger via boot or over Serial  
- ✅ Supports Windows, macOS, Linux, and Android  
- ✅ Lightweight, portable, and easy to use  

---

## 📦 Requirements

- [Arduino IDE Portable](https://www.arduino.cc/en/software)
- ESP32 Dev Board (e.g., ESP32-WROOM-32)  
- Micro USB Cable  
- BLE Keyboard Library ([ESP32-BLE-Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard))

---

## 🔧 Installation

1. **Install the ESP32 Board in Arduino IDE**  
   - Go to `File > Preferences`  
   - Add the following URL to *Additional Board Manager URLs*:  
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Go to `Tools > Board > Boards Manager`, search `esp32` and install V.2.0.7

2. **Install BLE Keyboard Library**  
   - Download the library ZIP: [ESP32-BLE-Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard/archive/refs/heads/master.zip)  
   - In Arduino IDE, go to `Sketch > Include Library > Add .ZIP Library...`  
   - Select the downloaded ZIP file.

3. **Select the Board and Port**  
   - Go to `Tools > Board > ESP32 Dev Module`  
   - Select the correct COM port under `Tools > Port`

4. **Open and Edit the Code**  
   - Open `Ducky.ino` in Arduino IDE  
   - Customize the payload as needed 

5. **Upload to ESP32**  
   - Click ✅ **Verify** then ⬆️ **Upload**  
   - Once uploaded, disconnect and power it externally

---

## 🚀 How to Use

1. **Power the ESP32 device**  
   It will start broadcasting as a Bluetooth keyboard.

2. **Wait for the Victim to Pair**  
   On first use, the victim must accept the pairing.  
   After this, the ESP32 will auto-connect silently in the future.

3. **Payload Execution**  
   Once connected, the predefined script will automatically run and execute on the victim’s machine.

---

## 📥 Downloads

ESP32 Serial Monitor GUI?

➡️ **Download it from the [Releases](https://github.com/Linuxndroid/Bluetooth-Ducky/releases)** section.

The monitor app allows you to:
- Send serial commands to your ESP32 device
- View real-time logs and responses
- Trigger payloads manually
- Customize interaction with your Bluetooth Ducky tool

> Available for **Windows (.exe)** — more platforms coming soon.

## 💻 Available Serial Commands

Use these commands via the Serial Monitor or GUI Monitor App:

| Command | Action |
|--------|--------|
| `notepad` | Open Notepad |
| `youtube <search>` | Search & open YouTube |
| `google <search>` | Search & open Google |
| `whatsapp <no> <msg>` | Send WhatsApp message |
| `wp-ss <no>` | Send screenshot via WhatsApp |
| `cmd` | Open Command Prompt |
| `shutdown` | Shutdown PC in 5 seconds |
| `run` | Open Run dialog (Win + R) |
| `url <command>` | Execute command in Run box |
| `lock` | Lock the PC |
| `close` | Close current app |
| `ENTER` | Press Enter key |
| `screenshot` | Take a screenshot |
| `CTRL+<key>` | Press CTRL with a key (e.g., `CTRL+A`) |
| `WIN`, `LEFT`, `RIGHT`, `UP`, `DOWN` | Arrow or Win keys |
| `WiFi` | Dump saved Wi-Fi passwords |
| `Fake` | Show fake system update |
| `Spam` | Display spam alert box |
| `help` | Show all commands |
| `About` | Show creator info |

# Disclaimer
<b>Linuxndroid Provides no warranty with this software and will not be responsible for any direct or indirect damage caused due to the usage of this tool.<br>
BLE-DUCKY is built for both Educational and Internal use ONLY.</b>

<br>
<p align="center">Made with ❤️ By <a href="https://www.youtube.com/channel/UC2O1Hfg-dDCbUcau5QWGcgg">Linuxndroid</a></p>

# Available Our [Hacking Course](https://linuxndroid.in)

# Follow Me on :

[![Instagram](https://img.shields.io/badge/IG-linuxndroid-yellowgreen?style=for-the-badge&logo=instagram)](https://www.instagram.com/linuxndroid)

[![Youtube](https://img.shields.io/badge/Youtube-linuxndroid-redgreen?style=for-the-badge&logo=youtube)](https://www.youtube.com/channel/UC2O1Hfg-dDCbUcau5QWGcgg)

[![Browser](https://img.shields.io/badge/Website-linuxndroid-yellowred?style=for-the-badge&logo=browser)](https://www.linuxndroid.in)

## 🧪 Example Payloads

```cpp
delay(1000);                        // Wait 1 second
typeSlow("https://www.instagram.com/linuxndroid");   // Type message
bleKeyboard.write(KEY_RETURN);      // Press Enter



