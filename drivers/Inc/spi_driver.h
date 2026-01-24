/*
 * spi_driver.h
 *
 *  Created on: Dec 16, 2025
 *      Author: DELL
 */

#ifndef INC_SPI_DRIVER_H_
#define INC_SPI_DRIVER_H_

#include <Inc/stm32f429xx.h>

/*
 * This is a Configuration structure for SPIx peripheral
 */
typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BugConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
} SPIx_Cfg_t;


/*
 * This is a Handle structure for a SPIx peripheral
 */
typedef struct
{
	// Pointer to hold the based address of the SPI peripheral
	SPIx_Type *pSPIx;

	SPIx_Cfg_t SPIConfig;
} SPIx_Handle_t;


/***********************************************************************************
 * 							APIs supported by this driver
 * 			For more information about the APIs check the function definitions
 ************************************************************************************/

/*
 * SPI Clock Control
 */
void SPI_PclkCtrl(SPIx_Type* pSPIx, uint8_t EnorDis);


/*
 * SPI Initialization and De-initialization
 */
void SPI_Init(SPIx_Handle_t *pSPIHandle);

void SPI_DeInint(SPIx_Type *pSPIx);

/*
 * Data Send and Receive
 */
void SPI_SenDatad(SPIx_Type* pSPIx, uint8_t *pTxBuff, uint32_t len);

void SPI_ReceiveData(SPIx_Type* pSPIx, uint8_t *pRxBuff, uint32_t len);


/*
 * SPI Interrupt Configuration
 */
void SPI_IRQInteruptConfig(uint8_t IRQNumber, uint8_t EnorDis);

void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);

void SPI_IRQHandling(SPIx_Handle_t *pSPIHandle);

#endif /* INC_SPI_DRIVER_H_ */
