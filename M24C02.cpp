#include "M24C02.h"

M24C02::M24C02( uint8_t i2c_address ) : I2C_device( i2c_address )
{
}

M24C02::~M24C02()
{
}

void M24C02::begin( void )
{
}

int M24C02::write( int byte_adr, uint8_t data )
{
	return reg_w( byte_adr, data );
}

uint8_t M24C02::read( int byte_adr )
{
	return reg_r( byte_adr );
}
