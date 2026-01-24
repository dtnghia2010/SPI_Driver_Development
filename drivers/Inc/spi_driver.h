/**
 * spi_driver.h
 *
 *  Created on: Dec 16, 2025
 *      Author: DELL
 */

#ifndef INC_SPI_DRIVER_H_
#define INC_SPI_DRIVER_H_

#include <stm32f429xx.h>

/**
 * This is a Configuration structure for SPIx peripheral
 */
typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
} SPIx_Cfg_t;


/**
 * This is a Handle structure for a SPIx peripheral
 */
typedef struct
{
	// Pointer to hold the based address of the SPI peripheral
	SPIx_Type *pSPIx;

	SPIx_Cfg_t SPIConfig;
} SPIx_Handle_t;


/**
 * @SPI_DeviceMode
 */
#define SPI_DEVICE_MODE_MASTER	1
#define SPI_DEVICE_MODE_SLAVE	0

/**
 * @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FD			0
#define SPI_BUS_CONFIG_HD			1
#define SPI_BUS_CONFIG_SP_RXONLY	2	// SP = SIMPLEX

/**
 * @SPI_SclkSpeed
 */
#define SPI_SCLK_SPEED_DIV2		0
#define SPI_SCLK_SPEED_DIV4		1
#define SPI_SCLK_SPEED_DIV8		2
#define SPI_SCLK_SPEED_DIV16	3
#define SPI_SCLK_SPEED_DIV32	4
#define SPI_SCLK_SPEED_DIV64	5
#define SPI_SCLK_SPEED_DIV128	6
#define SPI_SCLK_SPEED_DIV256	7

/**
 * @SPI_DFF
 */
#define SPI_DFF_8BITS	0
#define SPI_DFF_16BITs	1

/**
 * @SPI_CPOL
 */
#define SPI_CPOL_HIGH		1
#define SPI_CPOL_LOW		0

/**
 * @SPI_CPHA
 */
#define SPI_CPHA_FIRST_CAPTURE 		0
#define SPI_CPHA_SECOND_CAPTURE 	1

/**
 * @SPI_SSM
 */
#define SPI_SSM_DIS 	0
#define SPI_SSM_EN 		1

/************************************************************************************
 * 							APIs supported by this driver
 * 			For more information about the APIs check the function definitions
 ************************************************************************************/

/**
 * SPI Clock Control
 */
void SPI_PclkCtrl(SPIx_Type* pSPIx, uint8_t EnorDis);


/**
 * SPI Initialization and De-initialization
 */
void SPI_Init(SPIx_Handle_t *pSPIHandle);

void SPI_DeInint(SPIx_Type *pSPIx);

/**
 * Other Peipheral Control APIs
 */
void SPI_PeripheralControl(SPIx_Type* pSPIx, uint8_t EnorDis);

/**
 * Data Send and Receive
 */
void SPI_SendData(SPIx_Type* pSPIx, uint8_t *pTxBuff, uint32_t len);

void SPI_ReceiveData(SPIx_Type* pSPIx, uint8_t *pRxBuff, uint32_t len);


/**
 * SPI Interrupt Configuration
 */
void SPI_IRQInteruptConfig(uint8_t IRQNumber, uint8_t EnorDis);

void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);

void SPI_IRQHandling(SPIx_Handle_t *pSPIHandle);

#endif /** INC_SPI_DRIVER_H_ */
