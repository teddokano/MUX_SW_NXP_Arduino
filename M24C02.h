/** I2C multiplexer and switch operation library for Arduino
 *
 *  @author Tedd OKANO
 *
 *  Released under the MIT license License
 */

#ifndef ARDUINO_M24C02_H
#define ARDUINO_M24C02_H

#include <Arduino.h>
#include <stdint.h>

#include <I2C_device.h>

/** M24C02 class
 *	
 *  @class M24C02
 *
 *	M24C02 class is a sample code for the PCA9846PW-ARD operation
 *	It demonstrates the switch operation with EEPROM on the shield board 
 */

class M24C02 : public I2C_device
{
public:
	/** Create a M24C02 instance with specified address
	 *
	 * @param i2c_address I2C-bus address (default: (0xA0>>1))
	 */
	M24C02( uint8_t i2c_address = (0xA0 >> 1) );
	virtual ~M24C02();
	
	/** Begin the device operation
	 *
	 *	This method turns-on the device
	 */
	void begin( void );

	/** Write data
	 *
	 * @param byte_adr byte address
	 * @param data 1 byte data for writing
	 */
	int write( int byte_adr, uint8_t data );	

	/** Write data
	 *
	 * @param byte_adr byte address
	 * @return 1 byte read data
	 */
	uint8_t read( int byte_adr );	

};

#endif //	ARDUINO_M24C02_H
