# 💊 Medicine Reminder System using LPC21xx

This project is an **Embedded C based Medicine Reminder System** developed for the **LPC21xx (ARM7) microcontroller**. The system uses a **Real Time Clock (RTC)** to track time and alerts the user at a preset medicine time using a **buzzer 🔔 and LED 💡**. A **keypad-based menu** allows the user to edit the RTC time and medicine reminder time, while a **16x2 LCD 📟** displays real-time information and menu options.

## ✨ Features
⏰ Real Time Clock (RTC) support  
📟 LCD display for time, date, and menu  
⌨️ Keypad interface for user input  
🔔 Medicine reminder alert using buzzer  
💡 LED indication for alerts  
⚙️ Editable RTC and medicine reminder time  
📋 Menu-driven user interface  

## 🧰 Hardware Requirements
🧠 LPC21xx ARM7 Microcontroller  
📟 16x2 LCD Display  
⌨️ 4x4 Matrix Keypad  
🔔 Buzzer  
💡 LED  
🔘 Push Button (SW1)  
🔌 Power Supply  
🧵 Connecting Wires  

## 💻 Software Requirements
🛠️ Keil µVision IDE  
📜 Embedded C  
📦 LPC21xx device libraries  

## 📂 Project Structure
PROJECT_NAVN  
📄 project_main.c – Main application logic  
📄 rtc.c / rtc.h – Real Time Clock functions  
📄 lcd.c / lcd.h – LCD driver  
📄 kpm.c / kpm.h – Keypad driver  
📄 delay.c / delay.h – Delay routines  
📄 edit.c / edit.h – RTC and medicine time editing  
📄 defines.h – Common macros  
📄 types.h – Custom data types  
📄 pindefines.h – Pin configuration  
📄 lcd_defines.h – LCD commands  
📄 rtc_defines.h – RTC register macros  
📄 kpm_defines.h – Keypad macros  
📄 MINIPROJECT.uvproj – Keil project file  

## ⚙️ Working Principle
⏳ The RTC continuously keeps track of the current time and date.  
📟 The LCD displays this information in real time.  
⏰ When the RTC time matches the preset medicine reminder time, the buzzer sounds and the LED turns ON.  
🔘 Pressing the SW1 button opens a menu where the user can edit the RTC time or the medicine reminder time using the keypad.  

## ▶️ How to Run
1️⃣ Open Keil µVision IDE  
2️⃣ Load the MINIPROJECT.uvproj file  
3️⃣ Build the project  
4️⃣ Flash the program into the LPC21xx microcontroller  
5️⃣ Connect hardware as per pin definitions  
6️⃣ Power ON the system  

## 🏥 Applications
👵 Medicine reminder for elderly patients  
⏲️ Time-based alert systems  
🎓 Embedded systems learning project  
❤️ Healthcare monitoring devices  

## 👨‍💻 Author
**Naveen Gangaputhra**

## 📜 License
📘 This project is intended for **educational purposes** and can be freely modified and enhanced.
