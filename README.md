# 🟢 Morse Code Tool 🟢

Welcome to the **Morse Code Tool** repository! This project allows you to input Morse code using the M5StickC Plus, decode it into text, and display the result on a screen. Whether you're learning Morse code or just need a quick way to encode or decode messages, this tool has you covered! 🚀

![Morse Code Tool](https://via.placeholder.com/600x300.png?text=Morse+Code+Tool) <!-- You can replace this with an actual image of your project -->

## Features 🛠️
- **Morse Code Decoding**: Converts Morse code into text.
- **Real-time Input**: Input Morse code using button presses and see the decoded text appear on screen.
- **Reset Functionality**: Reset your input and start fresh.
- **Space Between Letters**: Automatically detects spaces between letters for proper formatting.
- **Display Final Message**: Show the complete decoded message by pressing a button.
  
## 🔥 How It Works
This tool uses the M5StickC Plus and its built-in buttons to input Morse code:
1. Press **BtnA** to input Morse code.
   - **Short press** (dot) → `.`
   - **Long press** (dash) → `-`
2. Wait 5 seconds to register a **space** between letters.
3. The tool displays the decoded text on the screen as you go.
4. Press **BtnB** to show the **final decoded message** on a clean screen.
5. **Hold BtnB for 5 seconds** to **reset** the tool.

## 📷 Demo
Here's a simple demo of how it works:

1. **Input Morse Code**:  
   Press `.-` → Displays: `A`

2. **Wait for Space**:  
   After waiting 5 seconds, the tool registers a space.

3. **Input Second Letter**:  
   Press `-...` → Displays: `A B`

4. **Press BtnB** to show final message:  
   Displays:  
