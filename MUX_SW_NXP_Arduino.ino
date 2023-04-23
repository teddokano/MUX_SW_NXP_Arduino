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
M24C02 eeprom;
M24C02 eeprom2( 0xA2 >> 1 );

void setup() {
  Serial.begin(9600);
  Serial.println("\n***** Hello, PCA9846! *****");

  Wire.begin();



  char test_str[] = "Hello, PCA9846 Arduino shield evaluation board test program";
  char read_str[ READ_BUFFER_SIZE ];

  Serial.print("read string: ");
  Serial.println(read_str);
  Serial.print("read string length: ");
  Serial.println(sizeof(read_str));

  Serial.print("test string: ");
  Serial.println(test_str);
  Serial.print("test string length: ");
  Serial.println(sizeof(test_str));

 sw.select(PCA9846::CH0 | PCA9846::CH1 | PCA9846::CH2 | PCA9846::CH3);
sw.select(PCA9846::CH0);

  delay(100);
    Serial.println(eeprom.ping());
  Serial.println(eeprom2.ping());

  eeprom.write(0, (uint8_t*)test_str, sizeof(test_str));
  delay(100);
  eeprom.read(0, (uint8_t*)read_str, READ_BUFFER_SIZE);

  Serial.print("read string: ");
  Serial.println(read_str);
  Serial.print("read string length: ");
  Serial.println(sizeof(read_str));

//  sw.select(0);
}

void loop() {
  static int count = 0;

  eeprom.write(0, count++);
  delay(10);

  Serial.println(eeprom.read(0), HEX);
  delay(1000);
}
