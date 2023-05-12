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

PCA9846 sw(Wire1);
M24C02 eeprom[] = {
  M24C02(Wire1, 0xA0 >> 1),
  M24C02(Wire1, 0xA2 >> 1),
  M24C02(Wire1, 0xA4 >> 1),
  M24C02(Wire1, 0xA6 >> 1),
};

void setup() {
  Serial.begin(9600);
  Serial.println("\n***** Hello, PCA9846! *****");

  Wire1.begin();

  char test_str[] = "EEPROM[*] is responding - Hello, PCA9846 Arduino shield evaluation board test program";

  Serial.print("test string: ");
  Serial.println(test_str);
  Serial.print("test string length: ");
  Serial.println(sizeof(test_str));

  sw.select(PCA9846::CH0 | PCA9846::CH1 | PCA9846::CH2 | PCA9846::CH3);

  for (int i = 0; i < sw.N_CH; i++) {
    test_str[7] = i + '0';
    eeprom[i].write(0, (uint8_t*)test_str, sizeof(test_str));
  }
}

void loop() {
  char str[] = "\n*** PCA9846 setting: only channel * is ON ***";

  Serial.println("\n*** PCA9846 setting: All channels ON ***");
  sw.select(PCA9846::CH0 | PCA9846::CH1 | PCA9846::CH2 | PCA9846::CH3);
  try_eeprom_read();

  delay(1000);

  for (int i = 0; i < sw.N_CH; i++) {
    str[35] = i + '0';
    Serial.println(str);
    sw.select(0x1 << i);
    try_eeprom_read();

    delay(1000);
  }
}

void try_eeprom_read(void) {
  char read_str[READ_BUFFER_SIZE];
  char str[] = "EEPROM[*] is not responding";

  for (int i = 0; i < sw.N_CH; i++) {
    if (eeprom[i].ping()) {
      eeprom[i].read(0, (uint8_t*)read_str, READ_BUFFER_SIZE);

      Serial.println(read_str);
    } else {
      str[7] = i + '0';
      Serial.println(str);
    }
  }
}
