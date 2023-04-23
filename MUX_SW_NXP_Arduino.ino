/** PCA9846 operation sample
 *
 *  Simple sample
 *
 *  @author  Tedd OKANO
 *
 *  Released under the MIT license License
 *
 *  About PCA9846:
 *    https://www.nxp.com/products/interfaces/ic-spi-i3c-interface-devices/ic-multiplexers-switches/four-channel-ultra-low-voltage-fm-plus-ic-bus-switch-with-reset:PCA9846
 */


#include "PCA9846.h"
#include "M24C02.h"

#define READ_BUFFER_SIZE 128

PCA9846 sw;
M24C02 eeprom[] = {
  M24C02(0xA0 >> 1),
  M24C02(0xA2 >> 1),
  M24C02(0xA4 >> 1),
  M24C02(0xA6 >> 1),
};

void setup() {
  Serial.begin(9600);
  Serial.println("\n***** Hello, PCA9846! *****");

  Wire.begin();

  char test_str[] = "EEPROM[*] : Hello, PCA9846 Arduino shield evaluation board test program     ";
  char read_str[READ_BUFFER_SIZE];

  Serial.print("test string: ");
  Serial.println(test_str);
  Serial.print("test string length: ");
  Serial.println(sizeof(test_str));

  sw.select(PCA9846::CH0 | PCA9846::CH1 | PCA9846::CH2 | PCA9846::CH3);

  for (int i = 0; i < sw.N_CH; i++) {
    test_str[7] = i + '0';
    eeprom[i].write(0, (uint8_t*)test_str, sizeof(test_str));
  }

  for (int i = 0; i < sw.N_CH; i++) {
    eeprom[i].read(0, (uint8_t*)read_str, READ_BUFFER_SIZE);

    Serial.print("read string: ");
    Serial.println(read_str);
  }
}

void loop() {
  static int count = 0;

  eeprom[0].write(0, count++);
  delay(10);

  Serial.println(eeprom[0].read(0), HEX);
  delay(1000);
}
