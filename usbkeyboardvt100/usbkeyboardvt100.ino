/*
 *  usbkeyboardvt100.ino
 */

//
// GLOBAL OPTIONS
//

// SWAPCAPS: If defined, LeftCtrl and CapsLock are swapped on USB Keyboard.
#define SWAPCAPS

// SWAPLFBAR: If defined, swap LineFeed and '|\' key codes for VT100.
//#define SWAPLFBAR

//
// END of GLOBAL OPTIONS
//

#include "usbkeyboardvt100.h"

#include <hidboot.h>
#include <usbhub.h>
#include <hiduniversal.h>

#include <TimerOne.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

// There are seven VT100 standard LED's. Another LED for CapsLock.
#define LED_0 2 // LED 4
#define LED_1 3 // LED 3
#define LED_2 4 // LED 2
#define LED_3 5 // LED 1
#define LED_4 6 // KBD LOCKED
#define LED_5 7 // LOCAL
#define LED_6 8 // ON LINE
#define LED_7 A0 // CapsLock
// Two extra LED's are not used
// #define LED_8 A2 // Unused
// #define LED_9 A3 // Unused

// Speaker output
#define SPEAKER A1 // Speaker output
#define SPK_INTERVAL 625 // T = 625us x2 = 1.25ms, 800Hz

// Status byte sent by VT100
int inData;
volatile byte vt100_command = 0x00;

// Whether CapsLock has just been pressed and held or not
int caps_lock_held = 0;

// Vt100 keyboard LED process status
int led_pins[] = {LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7};
int led_current = 0;
byte led_status = 0x00;
byte led_mask;

// Speaker toggle status, updated by Timer1 interrupt
volatile byte spk_status = 0x00;

// Send back key down information to VT100
void vt100_sendback_status(){
  int i;

  for(i=1; i<VT100KEYS; i++){  // Skip vt100_key_status[0] which is always open
    if(vt100_key_status[i]){
      Serial.write(vt100_key_tbl[i]);
    }
  }
  Serial.flush();
}

// Update LED status
void update_led_off(){

  digitalWrite(led_pins[led_current], LOW); // Turn off current LED for dynamic LED control

}

void update_led_on(){

  led_current = (led_current + 1) % 8;  // Next LED

  led_mask = 0x01 << led_current;
  if(led_status & led_mask){
    digitalWrite(led_pins[led_current], HIGH);
  }else{
    digitalWrite(led_pins[led_current], LOW);
  }

}

// Timer1 Interrupt Handler to toggle Speaker
void check_beep(){

  if(vt100_command & 0x80){
    if(spk_status){
      digitalWrite(SPEAKER, HIGH);
    }else{
      digitalWrite(SPEAKER, LOW);
    }
    spk_status = ~spk_status;
  }

}

//
// USB HID code based on
// https://github.com/felis/USB_Host_Shield_2.0/tree/master/examples/HID/USBHIDBootKbd
//

USB     Usb;
// USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);

//
// USB HID - KbdRptParser class
//

class KbdRptParser : public KeyboardReportParser
{
  protected:
    void OnControlKeysChanged(uint8_t before, uint8_t after);
    void OnKeyDown  (uint8_t mod, uint8_t key);
    void OnKeyUp  (uint8_t mod, uint8_t key);
    uint8_t HandleLockingKeys(USBHID* hid, uint8_t key);

};

void KbdRptParser::OnControlKeysChanged(uint8_t before, uint8_t after) {

  MODIFIERKEYS beforeMod;
  *((uint8_t*)&beforeMod) = before;
  MODIFIERKEYS afterMod;
  *((uint8_t*)&afterMod) = after;

#ifdef SWAPCAPS
// Left Ctrl as CapsLock
  if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) { // L-Ctrl status changed
    if(afterMod.bmLeftCtrl){ // Ctrl key down
      if(vt100_key_status[VT100CAPSLOCK] == 0){
        vt100_key_status[VT100CAPSLOCK] = 1;
        led_status |= 0x80; // LED_7: CapsLock on
        caps_lock_held = 1;
      }
    }else{ // Ctrl key up
      if(caps_lock_held == 1){ // CapsLock has just been turned on
          caps_lock_held = 0;
       }else{ // CapsLock is released
        vt100_key_status[VT100CAPSLOCK] = 0;
        led_status &= ~0x80; // LED_7: CapsLock LED off
//        caps_lock_held = 0;
      }
    }
  }

// Update both R-CTRL and SHIFT anyway
  if (afterMod.bmRightCtrl) { // Test RightCtrl
        vt100_key_status[VT100CTRL] = 1;
  }else{
        vt100_key_status[VT100CTRL] = 0;
  }
#else // SWAPCAPS undefined
  if (afterMod.bmLeftCtrl||afterMod.bmRightCtrl) { // Test Ctrl keys
        vt100_key_status[VT100CTRL] = 1;
  }else{
        vt100_key_status[VT100CTRL] = 0;
  }
#endif // SWAPCAPS

  if (afterMod.bmLeftShift||afterMod.bmRightShift) { // Test Shift keys
        vt100_key_status[VT100SHIFT] = 1;
  }else{
        vt100_key_status[VT100SHIFT] = 0;
  }

}

void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
  int vt100key_index;

  vt100key_index = usb_key_tbl[key];
  if((vt100key_index > 0) && (vt100key_index < VT100KEYS-1)){

#ifdef SWAPCAPS
    vt100_key_status[vt100key_index] = 1;
#else // SWAPCAPS undefined
    // Check CapsLock first
    if(vt100key_index == VT100CAPSLOCK){
      if(vt100_key_status[VT100CAPSLOCK]==0){
        vt100_key_status[VT100CAPSLOCK] = 1;
        led_status |= 0x80; // LED_7: CapsLock
        caps_lock_held = 1;
      }
    }else{
      vt100_key_status[vt100key_index] = 1;
    }
#endif // SWAPCAPS

  }
}

void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key)
{
  int vt100key_index;

  vt100key_index = usb_key_tbl[key];
  if((vt100key_index > 0) && (vt100key_index < VT100KEYS-1)){

#ifdef SWAPCAPS // CapsLock is checked in OnControlKeysChanged()
      vt100_key_status[vt100key_index] = 0;
#else // SWAPCAPS undefined
    // Check CapsLock first
    if(vt100key_index == VT100CAPSLOCK){
      if(caps_lock_held == 1){
          caps_lock_held = 0;
      }else{
        if(vt100_key_status[VT100CAPSLOCK]==1){
          vt100_key_status[VT100CAPSLOCK] = 0;
          led_status &= ~0x80; // LED_7: CapsLock
        }
      }
    }else{
      vt100_key_status[vt100key_index] = 0;
    }
#endif // SWAPCAPS
  }
}

// To override the parent which calls SetReport()
uint8_t KbdRptParser::HandleLockingKeys(USBHID* hid, uint8_t key){
    return 0;
}

;

//
// end of KbdRptParser class
//

KbdRptParser Prs;

//
// SETUP
//

void setup() {
  int i;

// Initialze LED output
  for(i=0; i < 8; i++){
    pinMode(led_pins[i], OUTPUT);
    digitalWrite(led_pins[i], LOW);
  }

// Start VT100 Keyboard UART communication
  Serial.begin(7867);

// Initialze Speaker output
  pinMode(SPEAKER, OUTPUT);
  digitalWrite(SPEAKER, LOW);

// initialze vt100_key_status
  for(i=0; i<VT100KEYS-1; i++){
      vt100_key_status[i] = 0;
  }
  vt100_key_status[VT100KEYS-1] = 1; // Always send <scan end>

// Start Timer Interrupt
  Timer1.initialize(SPK_INTERVAL); // SPK_INTERVAL = 625 for 800Hz
  Timer1.attachInterrupt(check_beep);

// Handle VT100 Power-on Self Test (POST)
#define POST_DELAY 3000 // 3 sec wait before post timeout
  int post_kbd_test = 1;
  int post_time;

  post_time = millis() + POST_DELAY;

  while(post_kbd_test && post_time > millis()){

    update_led_on();

    if(Serial.available() > 0){
      inData = Serial.read();
      if(inData != -1){
        vt100_command = (byte) inData;
        if(vt100_command & 0x40){ // Start scan bit = on
          vt100_sendback_status();
        }
        if(vt100_command == 0xff){ // Beep issued at the end of POST
            post_kbd_test = 2;
        }
        if(vt100_command == 0x00){ // Done beeping
           post_kbd_test = 0; // Break the while loop
        }
      }
    }

    update_led_off();

    led_status = led_status & 0x80 | vt100_command & 0x3f;
    if(led_status & 0x20){ // ON_LINE (bit 6) = ~LOCAL (bit 5)
      led_status &= ~0x40;
    }else{
      led_status |= 0x40;
    }
  } // POST is done

// initialize USB Host Shield
  if (Usb.Init() == -1){
    // If USB initialization fails, indicate error by turning on LED_7
    led_status = 0x80;
    while(true){ // Loop with LED control
      update_led_on();
      delay(15);
      update_led_off();
      delay(3);
    }
  }

//  delay( 200 );
  if(HidKeyboard.SetReportParser(0, &Prs)==false){
    // If HidKeyboard initialization fails, indicate the error by turning on LED_0 and LED_7
    led_status = 0x81;
    while(true){ // Loop with LED control
      update_led_on();
      delay(15);
      update_led_off();
      delay(3);
    }
  }

}

//
// LOOP
//

void loop() {
  int i;

// Update LED array
  update_led_off();

// Read and handle VT100 status byte
  if(Serial.available() > 0){
    inData = Serial.read();
    if(inData != -1){
      vt100_command = (byte) inData;

      if(vt100_command & 0x40){ // Start scan bit = on
        vt100_sendback_status();
       }

      led_status = led_status & 0x80 | vt100_command & 0x3f;
      if(led_status & 0x20){ // ON_LINE (bit 6) = ~LOCAL (bit 5)
        led_status &= ~0x40;
      }else{
        led_status |= 0x40;
      }
    }
  }

// Check beep
//  check_beep(); // is now handled in Timer1 Interrupt

// Update LED array
  update_led_on();

// USB Host Shield tasks
  Usb.Task();

}
