#pragma once

// LCD (ST7735)
#define TFT_WIDTH  80
#define TFT_HEIGHT 160
#define TFT_MOSI   3
#define TFT_SCLK   5
#define TFT_CS     6
#define TFT_DC     4
#define TFT_RST    1
#define TFT_BL     2

// SD Card (SPI)
#define SD_SCK     12
#define SD_MOSI    11
#define SD_MISO    13
#define SD_CS      10

// Peripherals
#define BTN_PIN    0
#define LED_PIN    40  // Built-in WS2812

// Settings
#define BUFFER_SIZE_PSRAM (1024 * 512) // 512KB Sniffing buffer