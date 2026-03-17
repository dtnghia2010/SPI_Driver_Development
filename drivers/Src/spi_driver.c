/**
 * spi_driver.c
 *
 *  Created on: Dec 16, 2025
 *      Author: DELL
 */


#include "spi_driver.h"
#include "stm32f429xx.h"


/************************************************************************************
 * 							APIs supported by this driver
 * 			For more information about the APIs check the function definitions
 ************************************************************************************/

/**
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


/**
 * SPI Initialization and De-initialization
 */
void SPI_Init(SPIx_Handle_t *pSPIHandle)
{

    // Enable SPI peripheral clock
    SPI_PclkCtrl(pSPIHandle->pSPIx, ENABLE);

    uint32_t SPI_Reg = 0;

    // 1. Config device mode
    SPI_Reg |= (pSPIHandle->SPIConfig.SPI_DeviceMode << 2U);

    // 2. Config the bug config
    if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
    {
        SPI_Reg &= ~(SPI_CR1_BIDIMODE_Msk << SPI_CR1_BIDIMODE_Pos);
        SPI_Reg &= ~(SPI_CR1_RXONLY_Msk << SPI_CR1_RXONLY_Pos);
    }
    else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
    {
        SPI_Reg |= (SPI_CR1_BIDIMODE_Msk << SPI_CR1_BIDIMODE_Pos);
    }
    else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SP_RXONLY)
    {
        SPI_Reg &= ~(SPI_CR1_BIDIMODE_Msk << SPI_CR1_BIDIMODE_Pos);
        SPI_Reg |= (SPI_CR1_RXONLY_Msk << SPI_CR1_RXONLY_Pos);
    }

    // 3. Config serial clock
    SPI_Reg |= (pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR_Pos);

    // 4. Config DFF
    SPI_Reg |= (pSPIHandle->SPIConfig.SPI_DFF << SPI_CR1_DFF_Pos);

    // 5. Config clock polarity
    SPI_Reg |= (pSPIHandle->SPIConfig.SPI_CPOL << SPI_CR1_CPOL_Pos);

    // 6. Config clock phase
    SPI_Reg |= (pSPIHandle->SPIConfig.SPI_CPHA << SPI_CR1_CPHA_Pos);

    // 7. Config software slave management
    SPI_Reg |= (pSPIHandle->SPIConfig.SPI_SSM << SPI_CR1_SSM_Pos);

    pSPIHandle->pSPIx->CR1 = SPI_Reg;
}

void SPI_DeInint(SPIx_Type *pSPIx)
{
	if (1)
	{
		if(pSPIx == SPI1)
		{
			SPI1_REG_RESET();
		}
		else if (pSPIx == SPI2)
		{
			SPI2_REG_RESET();
		}
		else if (pSPIx == SPI3)
		{
			SPI3_REG_RESET();
		}
		else if (pSPIx == SPI4)
		{
			SPI4_REG_RESET();
		}
		else if (pSPIx == SPI5)
		{
			SPI5_REG_RESET();
		}
		else if (pSPIx == SPI6)
		{
			SPI6_REG_RESET();
		}
	}
}

/**
 * Other Peipheral Control APIs
 */
void SPI_PeripheralControl(SPIx_Type* pSPIx, uint8_t EnorDis)
{
    if(EnorDis == ENABLE)
    {
        pSPIx->CR1 |= (SPI_CR1_SPE_Msk << SPI_CR1_SPE_Pos);
    }
    else
    {
        pSPIx->CR1 &= ~(SPI_CR1_SPE_Msk << SPI_CR1_SPE_Pos);
    }
}

/**
 * SSI configuration
 */
void SPI_SSIConfig(SPIx_Type* pSPIx, uint8_t EnorDis)
{
    if(EnorDis == ENABLE)
    {
        pSPIx->CR1 |= (SPI_CR1_SSI_Msk << SPI_CR1_SSI_Pos);
    }
    else
    {
        pSPIx->CR1 &= ~(SPI_CR1_SSI_Msk << SPI_CR1_SSI_Pos);
    }
}

void SPI_SSOEConfig(SPIx_Type* pSPIx, uint8_t EnorDis)
{
    if(EnorDis == ENABLE)
        pSPIx->CR2 |= (1 << SPI_CR2_SSOE_Pos);
    else
        pSPIx->CR2 &= ~(1 << SPI_CR2_SSOE_Pos);
}



uint8_t SPI_GetFlagStatus(SPIx_Type* pSPIx, uint8_t FLAG_NAME)
{
    if(pSPIx->SR & FLAG_NAME)
    {
        return FLAG_SET;
    }
    return FLAG_RESET;
}

/**
 * Data Send and Receive
 */
void SPI_SendData(SPIx_Type* pSPIx, uint8_t *pTxBuff, uint32_t len)
{
    while(len > 0)
    {
        // 1. Wait until TXE is set
        while(SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG) == FLAG_RESET);

        // 2. Check the DFF bit in CR1
        if(pSPIx->CR1 & (SPI_CR1_DFF_Msk << SPI_CR1_DFF_Pos))
        {
            // 16 bit DFF
            //a. Load the data into the DR
            pSPIx->DR = *((uint16_t *)pTxBuff);
            len-=2;
            pTxBuff+=2;
        }
        else
        {
            // 16 bit DFF
            //a. Load the data into the DR
            pSPIx->DR = *(pTxBuff);
            len--;
            pTxBuff++;

        }
    }
    while(SPI_GetFlagStatus(pSPIx, SPI_BSY_FLAG) == FLAG_SET);
}

void SPI_ReceiveData(SPIx_Type* pSPIx, uint8_t *pRxBuff, uint32_t len)
{
    while(len > 0)
    {
        // 1. Wait until TXE is set
        while(SPI_GetFlagStatus(pSPIx, SPI_RXNE_FLAG) == FLAG_RESET);

        // 2. Check the DFF bit in CR1
        if(pSPIx->CR1 & (SPI_CR1_DFF_Msk << SPI_CR1_DFF_Pos))
        {
            // 16 bit DFF
            //a. Load the data into the DR
            *((uint16_t *)pRxBuff) = pSPIx->DR;
            len-=2;
            pRxBuff+=2;
        }
        else
        {
            // 16 bit DFF
            //a. Load the data into the DR
            *((uint16_t *)pRxBuff) = pSPIx->DR;
            len--;
            pRxBuff++;
        }
    }
    while(SPI_GetFlagStatus(pSPIx, SPI_BSY_FLAG) == FLAG_SET);

}


/**
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
