# 💊 Smart Medicine Reminder System using LPC2148 (Proteus)

## 📌 Project Description
The **Smart Medicine Reminder System** is an embedded system project designed using the **LPC2124 ARM7 microcontroller**.  
It helps users remember their medicine schedule by using **RTC-based alerts**, a **16×2 LCD**, **keypad input**, **buzzer**, and **LED indications**.

This project is fully **simulated in Proteus**, making it ideal for learning and academic demonstration 📚.

---

## 🧠 Key Features
- ⏰ Real-Time Clock (RTC) based time tracking  
- 📟 16×2 LCD display for messages  
- 🔢 4×4 Matrix Keypad for user input  
- 🔔 Buzzer alert at medicine time  
- 💡 LED warning and status indication  
- ✅ Medicine taken confirmation  
- ❌ Missed medicine detection  
- 🧩 Menu-driven interface  

---

## 🛠️ Hardware Components (Proteus)
- LPC2148 ARM7 Microcontroller  
- 16×2 Alphanumeric LCD  
- 4×4 Matrix Keypad  
- Active Buzzer  
- Red LED  
- Push Buttons  
- 1kΩ Resistors  
- 3.3V / 5V Power Supply  

---

## 🧪 Software Tools Used
- 🖥️ Proteus Design Suite (Simulation)
- 🧑‍💻 Keil µVision (Embedded C)
- 🗂️ GitHub (Version Control)

---

## 🖼️ Proteus Simulation Screens & Explanation

### 🔹 1️⃣ LCD Interface & Pin Test

- Displays test characters on LCD
- Verifies D0–D7 data line connections
- Confirms LCD works in 8-bit mode ✅

---

### 🔹 2️⃣ RTC Date & Time Display
<img width="1203" height="820" alt="RTC" src="https://github.com/user-attachments/assets/27a38763-08c8-4a92-95df-08d03846f2fb" />

- Shows current time in HH:MM:SS format
- Displays date and day (DD/MM/YYYY)
- RTC runs continuously ⏳

---

### 🔹 3️⃣ Main Menu Screen
<img width="1200" height="819" alt="MENU" src="https://github.com/user-attachments/assets/a39dee94-e8c0-4f6b-847d-5b7de0b753d1" />

- Menu navigation using keypad
- User-friendly interface 🧭

---

### 🔹 4️⃣ Time & Medicine Setup Menu
<img width="1200" height="822" alt="RTC_EDIT" src="https://github.com/user-attachments/assets/3680caf9-64c2-4dce-9535-14c6c4e28d39" />

1: HR 2: MN 3: SC
4: MED_T 5: EXIT
- Set hours, minutes, seconds
- Configure medicine reminder time ⏰

---

### 🔹 5️⃣ Medicine Time Alert
<img width="1198" height="822" alt="MED_TIME" src="https://github.com/user-attachments/assets/80dc4563-44ec-4f1f-a64e-540b260f9507" />



- LCD shows **MEDICINE TIME**
- Buzzer turns ON 🔔
- LED glows for attention 💡

---

### 🔹 6️⃣ Take Medicine Alert
<img width="1205" height="844" alt="TAKE_MED" src="https://github.com/user-attachments/assets/217df2df-69ab-406d-953d-339a44e66f25" />

- LCD displays **TAKE MEDICINE**
- System waits for user confirmation
- Switch press confirms intake ✅

---

### 🔹 7️⃣ Medicine Taken Confirmation
<img width="1203" height="840" alt="MED_TAKEN" src="https://github.com/user-attachments/assets/cea2be5e-8d71-4d56-a683-9fbbc67d954b" />

- LCD shows **MEDICINE TAKEN**
- Buzzer turns OFF 🔕
- LED turns OFF
- Successful confirmation 🎉

---

### 🔹 8️⃣ Failure to Take Medicine
<img width="1186" height="831" alt="FAILED_MED" src="https://github.com/user-attachments/assets/c21d6966-8e98-4058-ad2c-59e80b15d3cd" />

- Triggered if switch is not pressed ❌
- LCD shows **FAILED TO TAKE MEDICINE**
- Warning LED remains ON 🚨

---

## 🔁 Working Flow
1. Power ON the system 🔌  
2. RTC starts time counting ⏱️  
3. User sets medicine time via keypad  
4. RTC compares with medicine time  
5. Alert triggers at match  
6. User confirms medicine intake  
7. Status is displayed on LCD  

---

## 🎯 Applications
- 👴 Elderly care systems  
- 🏥 Hospital medicine reminders  
- 🏠 Home healthcare automation  
- 🎓 Embedded systems learning  

---

## 🚀 Future Enhancements
- 📲 GSM/SMS alerts to caretaker  
- 💾 EEPROM data storage  
- 📱 Mobile app integration  
- 🔋 Battery backup support  

---

## 👨‍💻 Author
**Barika Naveen**  
🎓 EEE Student | Embedded Systems Enthusiast  
💡 Interested in ARM, Embedded C & IoT  

---

## ⭐ Support
If you like this project:
- ⭐ Star this repository  
- 🍴 Fork it  
- 🛠️ Contribute improvements  

Happy Coding! 🚀

