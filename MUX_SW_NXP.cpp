#include "MUX_SW_NXP.h"

/* PCA9846 class ******************************************/

PCA9846::PCA9846( uint8_t i2c_address ) : I2C_device( i2c_address )
{
}

PCA9846::~PCA9846()
{
}

void PCA9846::begin( void )
{
}

void PCA9846::select( channel flags )
{
	tx( (uint8_t *)(&flags), 1 );
}

channel PCA9846::select( void )
{
	uint8_t	flags;
	
	rx( &flags, 1 );
	
	return flags;
}
