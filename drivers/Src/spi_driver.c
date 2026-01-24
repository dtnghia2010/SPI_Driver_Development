/*
 * spi_driver.c
 *
 *  Created on: Dec 16, 2025
 *      Author: DELL
 */


#include "spi_driver.h"


/***********************************************************************************
 * 							APIs supported by this driver
 * 			For more information about the APIs check the function definitions
 ************************************************************************************/

/*
 * SPI Clock Control
 */
void SPI_PclkCtrl(SPIx_Type* pSPIx, uint8_t EnorDis)
{

}


/*
 * SPI Initialization and De-initialization
 */
void SPI_Init(SPIx_Handle_t *pSPIHandle)
{

}

void SPI_DeInint(SPIx_Type *pSPIx)
{

}

/*
 * Data Send and Receive
 */
void SPI_SenDatad(SPIx_Type* pSPIx, uint8_t *pTxBuff, uint32_t len)
{

}

void SPI_ReceiveData(SPIx_Type* pSPIx, uint8_t *pRxBuff, uint32_t len)
{

}


/*
 * SPI Interrupt Configuration
 */
void SPI_IRQInteruptConfig(uint8_t IRQNumber, uint8_t EnorDis)
{

}

void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority)
{

}

void SPI_IRQHandling(SPIx_Handle_t *pSPIHandle)
{

}


