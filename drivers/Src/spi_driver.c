/*
 * spi_driver.c
 *
 *  Created on: Dec 16, 2025
 *      Author: DELL
 */


#include "spi_driver.h"
#include "stm32f429xx.h"


/***********************************************************************************
 * 							APIs supported by this driver
 * 			For more information about the APIs check the function definitions
 ************************************************************************************/

/*
 * SPI Clock Control
 */
void SPI_PclkCtrl(SPIx_Type* pSPIx, uint8_t EnorDis)
{
	if (EnorDis == ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if (pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if (pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}
		else if (pSPIx == SPI4)
		{
			SPI4_PCLK_EN();
		}
		else if (pSPIx == SPI5)
		{
			SPI5_PCLK_EN();
		}
		else if (pSPIx == SPI6)
		{
			SPI6_PCLK_EN();
		}
	}
	else
	{

	}
}


/*
 * SPI Initialization and De-initialization
 */
void SPI_Init(SPIx_Handle_t *pSPIHandle)
{

}

void SPI_DeInint(SPIx_Type *pSPIx)
{
	if (1)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_REG_RESET();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_REG_RESET();
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_REG_RESET();
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_REG_RESET();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_REG_RESET();
		}
		else if (pGPIOx == GPIOF)
		{
			GPIOF_REG_RESET();
		}
		else if (pGPIOx == GPIOG)
		{
			GPIOG_REG_RESET();
		}
		else if (pGPIOx == GPIOH)
		{
			GPIOH_REG_RESET();
		}
		else if (pGPIOx == GPIOI)
		{
			GPIOI_REG_RESET();
		}
	}
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
