## DEVELOPERS NOTE! CODE MAY NOT WORK PERFECTLY AS I HAVE NOT BEEN ABLE TO TEST YET...

#Feel free to contact me on Discord or Instagram for any questions
#Discord: @12_ad
#Instagram: @299_bc

# 🟢 Morse Code Tool 🟢

Welcome to the **Morse Code Tool** repository! This project allows you to input Morse code using the M5StickC Plus, decode it into text, and display the result on a screen. Whether you're learning Morse code or just need a quick way to encode or decode messages, this tool has you covered! 🚀

![Morse Code Tool](https:placeholderimage.png) <!-- replace-->

## Features 🛠️
- **Morse Code Decoding**: Converts Morse code into text.
- **Real-time Input**: Input Morse code using button presses and see the decoded text appear on screen.
- **Reset Functionality**: Reset your input and start fresh.
- **Space Between Letters**: Automatically detects spaces between letters for proper formatting.
- **Display Final Message**: Show the complete decoded message by pressing a button.
  
## 🔥 How It Works
This tool uses the M5StickC Plus and its built-in buttons to input Morse code:
1. Press **BtnA** to input Morse code.
   - **Short press** (dot) → `.` (<300ms)
   - **Long press** (dash) → `-` (300ms> <1000ms)
2. Wait 3 seconds to register a **space** between letters.
3. The tool displays the decoded text on the screen as you go.
4. Press **BtnB** to show the **final decoded message** on a clean screen.
5. **Hold BtnB for 5 seconds** to **reset** the tool.

## 📷 Demo
Here's a simple demo of how it works:

1. **Input Morse Code**:  
   Press `.-` → Displays: `A`

2. **Wait for Space**:  
   After waiting 3 seconds, the tool registers a space.

3. **Input Second Letter**:  
   Press `-...` → Displays: `A B`

4. **Press BtnB** to show final message:  
   Displays:  



## 🧑‍💻 Installation

### 1. Install Arduino IDE
Make sure you have the [Arduino IDE](https://www.arduino.cc/en/software) installed on your computer.

### 2. Install M5StickC Plus Library
In Arduino IDE, go to **Sketch → Include Library → Manage Libraries** and search for **M5StickC**. Install the **M5StickCPlus** or the  **M5StickCPlus** library.

### 3. Upload Code
Upload the code provided in the `MorseCode.ino` file to your M5StickC Plus.

```cpp
#include <M5StickCPlus.h>
// code here...
```
## License

This project is licensed under the Creative Commons Attribution 4.0 International License (CC BY 4.0).
You may use, modify, and distribute the code, but please give credit to Artur (12-AD).

