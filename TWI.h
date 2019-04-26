#ifndef TWI_H_
#define TWI_H_


#include <avr/io.h>

#define F_SCL	100000UL
#define F_SCL_TWPS	0

/*TWPS1 	TWPS0 Prescaler Value
	0 		0 		1
	0 		1		4
	1 		0 		16
	1 		1		64
	*/

#define TWI_SDA_PORT	C
#define TWI_SDA_PIN		1

#define TWI_SCL_PORT	C
#define TWI_SCL_PIN		0



// Makra upraszczające dostęp do portów
// *** PORT
#define PORT(x) _PORT(x)
#define _PORT(x) (PORT##x)
// *** PIN
#define PIN(x) _PIN(x)
#define _PIN(x) (PIN##x)
// *** DDR
#define DDR(x) _DDR(x)
#define _DDR(x) (DDR##x)


#define TWI_SDA_HIGH 	PORT(TWI_SDA_PORT)|= (1<<PIN(TWI_SDA_PIN))
#define TWI_SDA_LOW 	PORT(TWI_SDA_PORT)&= ~(1<<PIN(TWI_SDA_PIN))
#define TWI_SDA_OUT 	DDR(TWI_SDA_PORT)|= (1<<PIN(TWI_SDA_PIN))
#define TWI_SDA_IN 		DDR(TWI_SDA_PORT)&= ~(1<<PIN(TWI_SDA_PIN))

#define TWI_SCL_HIGH 	PORT(TWI_SCL_PORT)|= (1<<PIN(TWI_SCL_PIN))
#define TWI_SCL_LOW 	PORT(TWI_SCL_PORT)&= ~(1<<PIN(TWI_SCL_PIN))
#define TWI_SCL_OUT 	DDR(TWI_SCL_PORT)|= (1<<PIN(TWI_SCL_PIN))
#define TWI_SCL_IN 		DDR(TWI_SCL_PORT)&= ~(1<<PIN(TWI_SCL_PIN))

//----- Prototypes ---------------------------------------------------//
void TWI_Init(void);
uint8_t TWI_start(void);
void TWI_EndTransmission(void);
uint8_t TWI_Status(void);

uint8_t TWI_Transmit(uint8_t Data);
uint8_t TWI_ReceiveACK(void);
uint8_t TWI_ReceiveNACK(void);

void print(uint8_t tab[]);

//enum TWI_Status_t TWI_PacketTransmit(const uint8_t SLA, const uint8_t SubAddress, uint8_t *Packet, const uint8_t Length);
//enum TWI_Status_t TWI_PacketReceive(const uint8_t SLA, const uint8_t SubAddress, uint8_t *Packet, const uint8_t Length);

void TWI_SetAddress(const uint8_t Address);
//--------------------------------------------------------------------//






#endif
