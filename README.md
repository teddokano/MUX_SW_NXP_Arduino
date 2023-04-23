# MUX_SW_NXP_Arduino
I2C multiplexer/switch device operation sample code for [Arduino](https://www.arduino.cc) 

> **Note**
This library works with [`I2C_device`](https://github.com/teddokano/I2C_device_Arduino) library together. Please be sure the `I2C_device` library is imported in your environment before trying to build. 

![Boards](https://github.com/teddokano/additional_files/blob/main/MUX_SW_NXP_Arduino/board.jpg)  
_PCA9846PW-ARD : Arduino® Shield Evaluation Board for I²C switch_

## What is this?
An Arduino library for I²C multiplexer/switch with sample code.  
This library provides simple API to switch I²C bus.  
Include device name header file (`PCA9846.h`) to use those class libraries. 

```cpp
#include <PCA9846.h>

PCA9846 sw;

void setup() {
  Wire.begin();

  sw.select(PCA9846::CH0 | PCA9846::CH1 | PCA9846::CH2 | PCA9846::CH3);
}

void loop() {
  ...
  sw.select(PCA9846::CH0 | PCA9846::CH1 | PCA9846::CH2 | PCA9846::CH3);	//	Select all channels
  ...
  sw.select(PCA9846::CH0);	//	Select channel-0 only
  ...
  sw.select(PCA9846::CH2 | PCA9846::CH3);	//	Select channel-2 and 3
}
```

## Supported device
Type#|Header file|Features|Interface|Evaluation board
---|---|---|---|---
[PCA9846](https://www.nxp.com/products/interfaces/ic-spi-i3c-interface-devices/ic-multiplexers-switches/four-channel-ultra-low-voltage-fm-plus-ic-bus-switch-with-reset:PCA9846)	|`PCA9846.h`	|Four-Channel Ultra-Low Voltage, Fm+ I²C-Bus Switch with Reset	|I²C Fast-mode Plus (1MHz)			|[PCA9846PW-ARD Arduino® Shield](https://www.nxp.com/design/development-boards/analog-toolbox/arduino-shields-solutions/pca9846pw-ard-arduino-shield:PCA9846PW-ARD)

# Getting started

Use Library manager in Arduino IDE for easy install

# What's inside?

## Examples
Examples are provided as scketch files.

### How to use?

After library install, Choose menu on Arduino-IDE: `File`→`Examples`→`MUX_SW_NXP_Arduino`→ PCA9846_demo_w_M24C02

### Sample code

This repo is including only one sample code: PCA9846_demo_w_M24C02.
It will demonstrate the PCA9846PW-ARD Arduino® Shield with devices on the board.  

The PCA9846PW-ARD Arduino® Shield has a PCA9846: I²C bus switch with 4x M24C02: EEPROMs.
The sample program writes data into all those EEPROM in `setup()` function. 
In `loop()` function, it repeats to access those EEPROM with changing the PCA9846 channel setting. 

# Document

For details of the library, please find descriptions in [this document](https://teddokano.github.io/MUX_SW_NXP_Arduino/annotated.html).

## Related libraries
Library|Feature|Target devices|Required library
---|---|---|---
[GPIO_NXP_Arduino](https://github.com/teddokano/GPIO_NXP_Arduino)				|GPIO libraries						|PCAL6408A, PCAL6416A, PCAL6524, PCAL6534, PCA9555, PCA9554	|[I2C_device_Arduino](https://github.com/teddokano/I2C_device_Arduino)
[LCDDriver_NXP_Arduino](https://github.com/teddokano/LCDDriver_NXP_Arduino)		|LCD driver libraries				|PCA8561						|[I2C_device_Arduino](https://github.com/teddokano/I2C_device_Arduino)
[LEDDriver_NXP_Arduino](https://github.com/teddokano/LEDDriver_NXP_Arduino)		|LED driver libraries				|PCA9955B, PCA9956B, PCA9957	|[I2C_device_Arduino](https://github.com/teddokano/I2C_device_Arduino)
[MUX_SW_NXP_Arduino](https://github.com/teddokano/MUX_SW_NXP_Arduino)			|I²C mux/switch libraries			|PCA9846						|[I2C_device_Arduino](https://github.com/teddokano/I2C_device_Arduino)
[RTC_NXP_Arduino](https://github.com/teddokano/RTC_NXP_Arduino)					|RTC libraries						|PCF2131, PCF85063A				|[I2C_device_Arduino](https://github.com/teddokano/I2C_device_Arduino)
[TempSensor_NXP_Arduino](https://github.com/teddokano/TempSensor_NXP_Arduino)	|Temperature sensor libraries		|LM75B, PCT2075, P3T1085		|[I2C_device_Arduino](https://github.com/teddokano/I2C_device_Arduino)
[I2C_device_Arduino](https://github.com/teddokano/I2C_device_Arduino)			|Base library for I²C operations	|none (can be applied as base class for all I²C targets)|---
