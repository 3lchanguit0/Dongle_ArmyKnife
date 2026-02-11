# ⚔️ 𝗗𝗼𝗻𝗴𝗹𝗲_𝗔𝗿𝗺𝘆𝗞𝗻𝗶𝗳𝗲 (𝗟𝗶𝗹𝘆𝗴𝗼 𝗧-𝗗𝗼𝗻𝗴𝗹𝗲 𝗦𝟯 𝗘𝗱𝗶𝘁𝗶𝗼𝗻)

This version of the **[USBArmyKnife](https://github.com/i-am-shodan/USBArmyKnife)** is built exclusively for the **Lilygo T-Dongle S3**. By moving away from "one-size-fits-all" code, this firmware is specifically optimized for the high-performance ESP32-S3 dual-core processor, the built-in color display, and its unique physical layout.

## 🚀 Key Enhancements

### 1. Advanced Tactical UI (ST7735 0.96" Screen)
Unlike generic builds that only show basic text, this version utilizes the **LVGL (Light and Versatile Graphics Library)** for a professional-grade interface.
*   **Real-time Dashboard:** View live graphs for "System Load" and "WiFi Traffic" directly on the device.
*   **On-device Menu:** Navigate using the onboard button (long-press/short-press) to launch payloads like "Ducky: RickRoll" or "WiFi: Deauth" without needing a phone or web interface.
*   **QR Code Deployment:** Generate on-screen QR codes for the internal WiFi AP or captured credential URLs for fast exfiltration to your mobile device.

### 2. High-Speed Logging & Exfiltration (MicroSD)
Utilize the "hidden" TF card slot inside the USB connector for professional data handling:
*   **Massive PCAP Storage:** Record continuous, high-speed WiFi packet captures (PCAPs) directly to the SD card.
*   **Payload Repository:** Store hundreds of Ducky Scripts in a structured folder system, browsable via the on-screen menu.
*   **Automated Exfiltration:** Configure the device to automatically copy specific file types (e.g., `.docx`, `.pdf`, `.kdbx`) from the host machine to the internal SD card using the MSC (Mass Storage Class) profile.

### 3. ESP32-S3 Performance "Hacks"
*   **In-Memory Sniffing:** Leverages 8MB of PSRAM to create massive buffers for WiFi sniffing, preventing packet loss during high-traffic deauth attacks or handshake captures.
*   **Dual-Core Processing:** The "Evil AP" runs on one core while the "USB HID/Ducky Interpreter" runs on the second core, ensuring keystroke timing is never interrupted by web traffic.
*   **Hardware Encryption:** Uses the S3’s hardware AES accelerator to encrypt captured logs on the SD card automatically.

### 4. Bluetooth Low Energy (BLE) 5.0 Attacks
*   **BLE HID Proxy:** Act as a BLE Keyboard; type on your phone and have the dongle "inject" those keys into the target computer over the USB cable.
*   **BLE Spam:** Built-in "AppleJuice" or "Android Fast Pair" spam capabilities to pop up connection messages on nearby mobile devices.

### 5. USB "Mode Morphing"
*   **Dynamic VID/PID:** Mimic specific hardware (e.g., a Logitech Keyboard, Apple Ethernet Adapter, or SanDisk Drive) based on the target OS it detects.
*   **Composite Device:** Enable HID, MSC, and CDC simultaneously to act as a keyboard, a disk drive for exfiltration, and a serial terminal all at once.

### 6. Physical Feedback (RGB LED)
The integrated LED provides instant status updates:
*   🔵 **Blue Pulsing:** Sniffing WiFi.
*   🔴 **Red Blinking:** Keystroke injection in progress.
*   🟢 **Solid Green:** Handshake captured and saved to SD.
*   🟣 **Purple:** Web UI active and client connected.

## 🛠️ Software Optimization
This build is "S3-Native," meaning:
*   **Removed HAL Layers:** No generic code for Pi Pico or S2. Pins are hard-coded for the T-Dongle S3 to ensure the lowest possible latency.
*   **DMA LCD Driving:** Uses Direct Memory Access to push graphics to the screen without using CPU cycles, leaving more power for attacks.

## 📋 Requirements
*   **Hardware:** [Lilygo T-Dongle S3](https://www.lilygo.cc/products/t-dongle-s3)
*   **Storage:** MicroSD Card (FAT32 formatted)
*   **Development:** PlatformIO (ESP32-S3 support required)

## 🚀 How to Flash
 1.   Install **VS Code** and the **PlatformIO extension**.
 2.   Create a folder named `Dongle_ArmyKnife` and paste the `platformio.ini` file.
 3.   Create the `src` and include folders and place the code snippets into their respective files.
 4.   Connect your **LilyGo T-Dongle S3**.
 5.   Hold the **Boot Button (GPIO 0)** while plugging it in to enter `bootloader mode` if it's the first flash.
 6.   Click **Upload** in PlatformIO.

## 👾 Credits & Acknowledgements

*   **[3lchanguit0](https://github.com/3lchanguit0)**
*   **[i-am-shodan](https://github.com/i-am-shodan)** : for the [USBArmyKnife](https://github.com/i-am-shodan/USBArmyKnife)
*   **[ekomsSavior](https://github.com/ekomsSavior)** : for her talent and her dope projects
*   **[bmorcelli](https://github.com/bmorcelli)** : for the inspiration with all his esp32's projects.

## ⚠️ Disclaimer
This tool is intended for educational purposes and authorized security testing only. Use it responsibly and within the boundaries of your country laws.

---
*   *Based on the USBArmyKnife project, optimized for the T-Dongle S3. Boosted by 3lchanguit0 2026.*
*   *Hack The Planet.* 🏴‍☠️🌍
