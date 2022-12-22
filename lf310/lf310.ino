/*
 Example sketch for the Logitech F310 gamepad
 */

// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif

#include <SPI.h>
#include "lf310.h"

USB Usb;
LF310 lf310(&Usb);

void setup() {
        Serial.begin(115200);
#if !defined(__MIPSEL__)
        while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif

        if (Usb.Init() == -1)
                
        // Set this to higher values to enable more debug information
        // minimum 0x00, maximum 0xff, default 0x80
        // UsbDEBUGlvl = 0xff;

        delay(200);
}

   uint8_t oldX = 128;
   uint8_t oldY = 128;
   uint8_t oldZ = 128;
   uint8_t oldRz = 128;
   uint8_t StickData[4];

void SendData(void){
  StickData[0] = lf310.lf310Data.Z;
  StickData[1] = lf310.lf310Data.Rz;
  StickData[2] = lf310.lf310Data.X;
  StickData[3] = lf310.lf310Data.Y;
  //Serial.write(データ（変数名）,データサイズ(byte));
  Serial.write(StickData, 4);
}
 
void loop() {
    /*
     * These four variable hold the "old" values of the joysticks so that action can be taken
     * only if they change.
     */
 
    Usb.Task();
    if (lf310.connected()) {

        SendData();
/*        Serial.print(StickData[0]);
        Serial.print(",");
        Serial.print(StickData[1]);
        Serial.print(",");
        Serial.print(StickData[2]);
        Serial.print(",");
        Serial.print(StickData[3]);
        Serial.println();*/
/*        if (lf310.buttonClickState.Xbutton) {
            Serial.print(F("X button "));
        }
      
        if (lf310.buttonClickState.Abutton) {
            Serial.print(F("A button "));
        }
      
        if (lf310.buttonClickState.Bbutton) {
            Serial.print(F("B button "));
        }
      
        if (lf310.buttonClickState.Ybutton) {
            Serial.print(F("Y button "));
        }
      
        if (lf310.buttonClickState.LBbutton) {
            Serial.print(F("LB button "));
        }
      
        if (lf310.buttonClickState.RBbutton) {
            Serial.print(F("RB button "));
        }
      
        if (lf310.buttonClickState.LTbutton) {
            Serial.print(F("LT button "));
        }
      
        if (lf310.buttonClickState.RTbutton) {
            Serial.print(F("RT button "));
        }
      
        if (lf310.buttonClickState.Backbutton) {
            Serial.print(F("Back button "));
        }
        
    }
    Serial.println();*/
    }
}
