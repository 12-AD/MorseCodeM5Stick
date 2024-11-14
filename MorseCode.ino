#include <M5StickCPlus.h>
#include <string>

String morseInput = ""; // Store the Morse code input for each letter
String plainText = "";  // Store the final decoded message
unsigned long lastPressTime = 0;
bool dashDetected = false;

const int dotThreshold = 300;      // Threshold for distinguishing dot (short press)
const int dashThreshold = 1000;    // Threshold for distinguishing dash (long press)
const int spaceThreshold = 3000;   // Threshold for detecting a space between letters
const int resetThreshold = 5000;   // Threshold for holding BtnB to reset

// Morse code map
const String morseCodeTable[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                                   "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                                   "..-", "...-", ".--", "-..-", "-.--", "--..", // Letters A-Z
                                   "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."}; // Numbers 0-9
const char asciiTable[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                             'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                             'U', 'V', 'W', 'X', 'Y', 'Z',
                             '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Function to convert morse code to character
char morseToChar(String morse) {
    for (int i = 0; i < 36; i++) {
        if (morse == morseCodeTable[i]) return asciiTable[i];
    }
    return '?'; // Return '?' if no match
}

void setup() {
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.setTextSize(2);
    M5.Lcd.println("Morse Code Converter");
    lastPressTime = millis();
}

void loop() {
    M5.update();
    unsigned long currentTime = millis();

    // Detect dot or dash from BtnA
    if (M5.BtnA.wasReleased()) {
        int pressDuration = M5.BtnA.getPressDuration();

        if (pressDuration < dotThreshold) {
            morseInput += "."; // Dot
        } else if (pressDuration < dashThreshold) {
            morseInput += "-"; // Dash
        }
        lastPressTime = currentTime;
        dashDetected = true;
    }

    // Check for space between letters
    if (dashDetected && (currentTime - lastPressTime > spaceThreshold)) {
        char decodedChar = morseToChar(morseInput);
        plainText += decodedChar;
        M5.Lcd.print(decodedChar);  // Display on screen
        morseInput = "";            // Reset for the next letter
        dashDetected = false;
        lastPressTime = currentTime;
    }

    // Long pause for space between words
    if (currentTime - lastPressTime > spaceThreshold * 3) {
        plainText += " ";
        M5.Lcd.print(" ");          // Display space on screen
        lastPressTime = currentTime;
    }

    // Process final text when BtnB is pressed
    if (M5.BtnB.wasPressed()) {
        M5.Lcd.fillScreen(BLACK);         // Clear the screen
        M5.Lcd.setCursor(0, 0);
        M5.Lcd.println("Final Message:");
        M5.Lcd.println(plainText);        // Display the full message
    }

    // Reset everything if BtnB is held for over 5 seconds
    if (M5.BtnB.pressedFor(resetThreshold)) {
        morseInput = "";
        plainText = "";
        M5.Lcd.fillScreen(BLACK);         // Clear the screen
        M5.Lcd.setCursor(0, 0);
        M5.Lcd.println("Reset Complete");
    }
}
