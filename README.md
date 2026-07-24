# 🚀 STM32F103C8T6 I2C OLED SSD1306 Display




\

## 📌 Project Overview

This project demonstrates how to interface a **128×64 SSD1306 OLED display** with the **STM32F103C8T6 (Blue Pill)** microcontroller using the **I2C communication protocol**.

The project is developed in **STM32CubeIDE** using **Embedded C** and **register-level programming**, providing a practical understanding of low-level STM32 peripheral configuration and OLED display control.

The OLED is used to display custom text such as **SHAIK** and **RIZWAN BASHA** using page and column addressing.

---

## ✨ Features

* 🔹 STM32F103C8T6 microcontroller
* 🔹 SSD1306 128×64 OLED display
* 🔹 I2C1 communication
* 🔹 Register-level programming
* 🔹 Direct STM32 peripheral register configuration
* 🔹 OLED initialization and control
* 🔹 Page and column addressing
* 🔹 Custom character font display
* 🔹 OLED screen clearing
* 🔹 Text display using custom 5×7 fonts
* 🔹 Developed using STM32CubeIDE

---

## 🛠️ Hardware Requirements

| Component               | Quantity    |
| ----------------------- | ----------- |
| STM32F103C8T6 Blue Pill | 1           |
| SSD1306 128×64 I2C OLED | 1           |
| ST-LINK V2 Programmer   | 1           |
| Jumper Wires            | As required |
| USB Cable               | 1           |

---

## 🔌 Circuit Connections

| STM32F103C8T6 | SSD1306 OLED |
| ------------- | ------------ |
| PB6           | SCL          |
| PB7           | SDA          |
| 3.3V          | VCC          |
| GND           | GND          |

### Communication

```text
        STM32F103C8T6
        ┌───────────────┐
        │               │
        │   PB6 ────────┼──── SCL
        │               │
        │   PB7 ────────┼──── SDA
        │               │
        │   3.3V ───────┼──── VCC
        │               │
        │   GND ────────┼──── GND
        │               │
        └───────────────┘
                │
                │ I2C
                ▼
        ┌───────────────┐
        │ SSD1306 OLED  │
        │   128 × 64    │
        └───────────────┘
```

---

## ⚙️ Software Requirements

* **STM32CubeIDE**
* **ARM GNU Toolchain**
* **ST-LINK Utility / STM32CubeProgrammer**
* **Git & GitHub** (optional)

---

## 📂 Project Structure

```text
STM32F103C8T6-I2C-OLED-SSD1306
│
├── Inc/
│
├── Src/
│   └── main.c
│
├── .project
├── .cproject
├── .gitignore
└── README.md
```

---

## 🧠 Working Principle

The STM32F103C8T6 communicates with the SSD1306 OLED through the **I2C1 peripheral**.

The program performs the following operations:

```text
STM32 Startup
      │
      ▼
GPIO Initialization
      │
      ▼
I2C1 Initialization
      │
      ▼
SSD1306 OLED Initialization
      │
      ▼
Clear OLED Display
      │
      ▼
Set OLED Page
      │
      ▼
Set OLED Column
      │
      ▼
Send Character Data
      │
      ▼
Display Text
```

The OLED uses **8 pages**, where each page represents **8 vertical pixels**.

```text
128 × 64 OLED

Page 0  ─────────────── 8 pixels
Page 1  ─────────────── 8 pixels
Page 2  ─────────────── 8 pixels
Page 3  ─────────────── 8 pixels
Page 4  ─────────────── 8 pixels
Page 5  ─────────────── 8 pixels
Page 6  ─────────────── 8 pixels
Page 7  ─────────────── 8 pixels

Total = 64 vertical pixels
```

---

## 🖥️ Display Output

The project demonstrates displaying custom text on the OLED:

```text
┌──────────────────────────────┐
│                              │
│                              │
│            any text          │
│                              │
│                              │
│                              │
│                              │
│                              │
└──────────────────────────────┘
```

---

## 🔧 Key Functions

| Function                      | Purpose                       |
| ----------------------------- | ----------------------------- |
| `GPIO_Init()`                 | Configures STM32 GPIO pins    |
| `I2C1_Init()`                 | Initializes I2C1 peripheral   |
| `I2C_Start()`                 | Generates I2C START condition |
| `I2C_Address()`               | Sends OLED I2C address        |
| `I2C_Write()`                 | Transmits data over I2C       |
| `I2C_Stop()`                  | Generates I2C STOP condition  |
| `OLED_Command()`              | Sends command to SSD1306      |
| `OLED_Data()`                 | Sends display data            |
| `OLED_Init()`                 | Initializes SSD1306 OLED      |
| `OLED_SetPage()`              | Selects OLED page             |
| `OLED_SetColumn()`            | Selects OLED column           |
| `OLED_Clear()`                | Clears OLED display           |
| `OLED_Char()`                 | Displays custom character     |
| `OLED_Display_SHAIK()`        | Displays `SHAIK`              |
| `OLED_Display_RIZWAN_BASHA()` | Displays `RIZWAN BASHA`       |

---

## 📚 Concepts Learned

This project provides practical experience with:

* Embedded C programming
* STM32F103C8T6 architecture
* I2C communication
* SSD1306 OLED controller
* GPIO configuration
* Peripheral register programming
* I2C START and STOP conditions
* I2C address transmission
* OLED command and data communication
* OLED page addressing
* OLED column addressing
* Custom bitmap fonts
* Debugging embedded systems

---

## 🚀 Future Improvements

Possible enhancements include:

* 📝 Display larger fonts
* 🎨 Add custom graphics and icons
* 😊 Add emoji bitmap images
* 🕌 Add custom symbols and logos
* ⏱️ Add scrolling text
* 🔢 Display numbers and counters
* 📊 Display sensor data
* 🌡️ Interface temperature and humidity sensors
* 🔄 Add real-time data updates
* 🎮 Create an OLED-based user interface

---

## 🎯 Applications

This OLED interface can be used in:

* Embedded systems
* IoT devices
* Sensor monitoring systems
* Industrial control panels
* Portable electronic devices
* Robotics projects
* Home automation
* Digital displays
* Microcontroller-based user interfaces

---

## 👨‍💻 Author

**SHAIK RIZWAN BASHA**

Electronics and Communication Engineering | Embedded Systems Enthusiast

---

## ⭐ Support

If you find this project useful, consider giving the repository a ⭐ **Star** and following the project for future updates.

---

## 📜 License

This project is open-source and available for educational and learning purposes.
