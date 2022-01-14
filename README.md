# USB Keyboard Shield for VT100

__Rev. 2.1__

## About

This shield connects a standard USB keyboard to the DEC VT100 terminal.

### Features

* All keys on the VT100 keyboard are mapped to the USB keyboard keys.
* VT100 keyboard LEDs and bell are emulated on the shield PCB.

The Gerber file, BOM, schematics and Arduino sketch for the shield are included in this repo. For the steps to assemble, program and connect the shields, please see the sections below.

__Note:__ this shield uses the USB Host Shield from Circuits@Home.

Please use the information in this repo at your own risk. No warranty or guarantee is provided.

## Required Components

- USB Keyboard Shield for VT100 (the shield from this repo)
- [USB Host Shield by Circuits@Home](https://www.circuitsathome.com/arduino_usb_host_shield_projects/), the "full-sized board"
- Arduino Uno
- Keyboard cable for VT100 (see "Keyboard Cable" below)
- USB Keyboard

## Steps

1. Assemble the shield
2. Build a keyboard cable
3. Program the Arduino
4. Connect the shields and cables

The details of each step are described in the next few sections.

## Assemble the Shield

The USB Keyboard Shield for VT100 can be assembled using the following info:

- PCB Gerber File: [usbkbd_vt100_2_1_gerber.zip](./usbkbd_vt100_2_1_gerber.zip)
- Schematic: [usbkbd_vt100_sch.pdf](./usbkbd_vt100_sch.pdf)
- BOM: [usbkbd_vt100_BOM_2_1.pdf](./usbkbd_vt100_BOM_2_1.pdf)

## Build the Keyboard Cable

To make the keyboard cable, connect these components:

 - 1/4 inch stereo plug/cable
 - 5-pin header connector

__PIN CONNECTIONS__

| Pin | Plug |  Value |
|-|-|-|
| 1* | - | (spk+)* |
| 2* | - | (spk-)* |
| 3 | Tip | +12V |
| 4 | Sleeve | GND |
| 5 | Ring | Signal |

  \* optional

The pin connector is attached to J1 header on the USB Keyboard shield for VT100. The stereo plug is connected to the keyboard port on VT100 terminal.

![vt100KeyboardCable.jpg](./images/vt100KeyboardCable1.jpg)

![usbkeyboardshieldCable_2_1.jpg](./images/usbkeyboardshieldCable_2_1.jpg)

## Program the Arduino Uno

It is recommended to program the Arduino Uno before attaching the shields.

1. Install [USB Host Shield Library 2.0](https://github.com/felis/USB_Host_Shield_2.0) and [Timer1 Library](http://playground.arduino.cc/Code/Timer1) into Arduino IDE.

2. Clone or download this project.

3. Open the sketch `usbkeyboardvt100/usbkeyboardvt100.ino` in Arduino IDE, and program the Arduino Uno.

### Configuration Options

There are two options in `usbkeyboardvt100.ino`:
```
// SWAPCAPS: If defined, LeftCtrl and CapsLock are swapped on USB Keyboard.
#define SWAPCAPS

// SWAPLFBAR: If defined, swap LineFeed and '|\' key codes for VT100.
//#define SWAPLFBAR
```

Comment out/uncomment the `#define` lines as needed.

## Connect the Shields and Cables

1. Connect the USB keyboard to the USB connector on the USB Host Shield.
2. Connect the keyboard cable for VT100 to the J1 header on the USB Keyboard Shield.
3. Connect the keyboard cable to the keyboard port on VT100 terminal.
4. Stack and connect the Arduino Uno, the USB Host Shield, and the USB Keyboard Shield, in this order, from the bottom to the top (see the iamge below).
5. No external power supply is needed. The power is supplied via the VT100 keyboard cable.

![shieldstack_2_1.jpg](./images/shieldstack_2_1.jpg)

## Key Mappings

Some hard-to-guess keys:

| VT100 Key | USB Keyboard Key |
|-|-|
| SET UP | F1, SysRq |
| CTRL | Caps Lock |
| CAPS LOCK | Left Ctrl |
| BREAK | Break |
| LINE FEED | End |
| NO SCROLL | Scroll Lock |
| PF1 | Num Lock, F9 |
| PF2 | (numpad) /, F10 |
| PF3 | (numpad) *, F11 |
| PF4 | Page Up, F12 |
|(numpad) , | (numpad) + |

The key mappings are defined in `usb_key_tbl[]` in `usbkeyboardvt100.h`. Also see "Configuration Options" above.

## Reference Configuration

The following configuration was used during development of this shield:

- USB Host Shield 2.0
- Arduino Uno R3
- VT100-WA / VT-180
- USB Keyboards: HP K1500 / Logitech K310

## Known Issues

1. Keyboard connected via a USB hub is not supported.

## GPL

The code is released under the GNU General Public License.
