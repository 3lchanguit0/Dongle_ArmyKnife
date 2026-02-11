#include <esp_wifi.h>

void startSniffing() {
    esp_wifi_set_promiscuous(true);
    esp_wifi_set_promiscuous_rx_cb([](void* buf, wifi_promiscuous_pkt_type_t type) {
        // Direct buffer copy to PSRAM for logging
        // No serial prints here (too slow for S3 line rate)
    });
}