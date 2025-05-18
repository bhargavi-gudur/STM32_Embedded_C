# 🚀 STM32 Embedded C – GPIO Pin Toggle Project

## 📘 Overview

This project is a **bare-metal Embedded C implementation** for STM32 microcontrollers. It includes peripheral-level driver development focused on **GPIO**, with extensions possible for **SPI**, **UART**, and **I2C**. Development is done using **Keil uVision** and documented/version-controlled via **Visual Studio Code** + GitHub.

---

## 🧰 Tools & Environment

* **Microcontroller**: STM32 (e.g., STM32F105)
* **IDE**: [Keil µVision5](https://www.keil.com/download/)
* **Editor**: [Visual Studio Code](https://code.visualstudio.com/)
* **Version Control**: Git + GitHub
* **Language**: Embedded C

---

## 📂 Folder Structure

```
STM32_Embedded_C/
├── gpio_pin/
│   ├── main.c                  # Application code
│   ├── startup_stm32.s         # Startup file
│   ├── gpio_pin.uvprojx        # Keil project file
│   ├── gpio_pin.uvoptx         # Keil configuration file
│   ├── RTE/                    # Run-Time Environment configuration
│   └── ...
└── README.md                   # Project documentation
```

---

## 🛠️ Setup Instructions

1. Install **Keil uVision5**.
2. Clone the repository:

   ```bash
   git clone https://github.com/bhargavi-gudur/STM32_Embedded_C.git
   ```
3. Open the project in Keil:

   * Navigate to the `gpio_pin/` folder.
   * Open `gpio_pin.uvprojx`.
4. Build and flash the project to your STM32f105 board.

---

## 📁 Documentation Workflow (Keil + VSCode)

* Use **Keil** for writing and building firmware.
* Open the same project folder in **VSCode** to:

  * Add comments using **Doxygen-style headers**:

    ```c
    /**
     * @file main.c
     * @brief Toggles a GPIO pin on STM32.
     */
    ```
  * Stage and commit your work via VSCode Git panel.
  * Push changes to GitHub.

---

## 📦 Git Best Practices

1. Use `.gitignore` to exclude build outputs:

   ```gitignore
   *.axf
   *.o
   *.lst
   *.map
   *.uvoptx
   *.uvgui.*
   .vscode/
   build/
   ```
2. If unwanted files were already pushed, run:

   ```bash
   git rm -r --cached .
   git add .
   git commit -m "Cleaned up ignored files"
   git push
   ```
3. To fix CRLF warnings:

   ```bash
   git config --global core.autocrlf input
   ```

---

## 🧠 Future Scope

* Add drivers for:

  * SPI communication
  * UART serial communication
  * I2C sensors
* Port to other STM32 boards or toolchains (e.g., STM32CubeIDE)

---

## 🙇‍♀️ Author

**Bhargavi Gudur**
Embedded Software Engineer | STM32 | Bare-metal C | GitHub
🔗 [GitHub Profile](https://github.com/bhargavi-gudur)

---
