#include <Arduino.h>
#include "config.h"
#include "USB.h"
#include "USBHIDKeyboard.h"
#include <lvgl.h>
#include <TFT_eSPI.h>

// Global Objects
USBHIDKeyboard Keyboard;
TFT_eSPI tft = TFT_eSPI();

// Task Handles
TaskHandle_t WiFiTask;

void coreRadioTask(void * pvParameters) {
    // This runs on Core 0: Sniffing, Deauth, BLE Spam
    for(;;) {
        // WiFi Sniffer logic here
        vTaskDelay(1); 
    }
}

void setup() {
    Serial.begin(115200);
    
    // 1. Initialize PSRAM
    if(psramInit()){
        Serial.println("PSRAM Ready");
    }

    // 2. Initialize USB Morphing (Default: Keyboard)
    USB.VID(0x046D); // Logitech
    USB.PID(0xC31C); // Keyboard
    Keyboard.begin();
    USB.begin();

    // 3. Initialize Display & LVGL (DMA Enabled)
    tft.init();
    tft.setRotation(1);
    tft.setSwapBytes(true);
    // LVGL Init code would follow here...

    // 4. Start Radio Core
    xTaskCreatePinnedToCore(coreRadioTask, "WiFiTask", 10000, NULL, 1, &WiFiTask, 0);
}

void loop() {
    // UI Refresh and Button handling on Core 1
    lv_timer_handler(); 
    delay(5);
}