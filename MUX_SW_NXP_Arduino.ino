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

PCA9846 sw;
M24C02  eeprom;

void setup() {
  Serial.begin(9600);
  Serial.println("\n***** Hello, PCA9846! *****");

  Wire.begin();

  sw.select( PCA9846::CH0 | PCA9846::CH1 | PCA9846::CH2 | PCA9846::CH3 );
  sw.select( 0 );
}

void loop() {
  static int count  = 0;

  eeprom.write( 0, count++ );
  delay( 10 );

  Serial.println(eeprom.read( 0 ), HEX);
  delay( 1000 );
}
