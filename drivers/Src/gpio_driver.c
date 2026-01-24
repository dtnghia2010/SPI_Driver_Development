/*
 * gpio_driver.c
 *
 *  Created on: Dec 16, 2025
 *      Author: DELL
 */

#include <gpio_driver.h>
#include <stm32f429xx.h>

/***********************************************************************************
 * @fn					- GPIO_PclkCtrl
 *
 * @brief				- This function enables or disables peripheral clock for the given GPIO Port
 *
 * @param[in]			- Base address of the GPIO Port
 * @param[in]			- ENABLE or DISABLE Macros
 * @param[in]			-
 *
 * @return				- none
 *
 * @Note				- none
 */


/*
 * GPIO Clock Control
 */
void GPIO_PclkCtrl(GPIOx_Type* pGPIOx, uint8_t EnorDis)
{
	if (EnorDis == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if (pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		else if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
		else if (pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	else
	{

	}
}


/*
 * GPIO Initialization and De-initialization
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;
	uint32_t register_value = 0;
	//1. Configure the mode of the gpio pin
	if(pGPIOHandle->GPIO_PinCFG.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		temp = (pGPIOHandle->GPIO_PinCFG.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinCFG.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_PinCFG.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->MODER |= temp;
	}
	else
	{
		if(pGPIOHandle->GPIO_PinCFG.GPIO_PinMode <= GPIO_MODE_IT_FT)
		{
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinCFG.GPIO_PinNumber);
		}
		else if (pGPIOHandle->GPIO_PinCFG.GPIO_PinMode <= GPIO_MODE_IT_RT)
		{

		}
		else if (pGPIOHandle->GPIO_PinCFG.GPIO_PinMode <= GPIO_MODE_IT_RFT)
		{

		}
	}
	temp = 0;

	//2. Configure the speed
	temp = (pGPIOHandle->GPIO_PinCFG.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinCFG.GPIO_PinNumber));
	register_value = pGPIOHandle->pGPIOx->OSPEEDR;
	register_value &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinCFG.GPIO_PinNumber));
	register_value |= temp;
	pGPIOHandle->pGPIOx->OSPEEDR = register_value;
	temp = 0; register_value = 0;

	//3. Configure the pupd settings
	temp = (pGPIOHandle->GPIO_PinCFG.GPIO_PinPuPdCtrl << (2 * pGPIOHandle->GPIO_PinCFG.GPIO_PinNumber));
	register_value = pGPIOHandle->pGPIOx->PUPDR;
	register_value &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinCFG.GPIO_PinNumber));
	register_value |= temp;
	pGPIOHandle->pGPIOx->PUPDR = register_value;
	temp = 0; register_value = 0;

	//4. Configure the optype
	temp = (pGPIOHandle->GPIO_PinCFG.GPIO_PinOPType << (2 * pGPIOHandle->GPIO_PinCFG.GPIO_PinNumber));
	register_value = pGPIOHandle->pGPIOx->OTYPER;
	register_value &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinCFG.GPIO_PinNumber));
	register_value |= temp;
	pGPIOHandle->pGPIOx->OTYPER = register_value;
	temp = 0; register_value = 0;

	//5. Configure the alt function
	if(pGPIOHandle->GPIO_PinCFG.GPIO_PinAltMode == GPIO_MODE_ALFN)
	{
		uint32_t temp1 = 0, temp2 = 0;
		temp1 = pGPIOHandle->GPIO_PinCFG.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinCFG.GPIO_PinNumber % 8;
		register_value = pGPIOHandle->pGPIOx->AFR[temp1];
		register_value &= ~(0xF << (4 * temp2));
		register_value |= (pGPIOHandle->GPIO_PinCFG.GPIO_PinAltMode << (4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] = register_value;
		temp1 = 0; temp2 = 0; register_value = 0;
	}


}

void GPIO_DeInint(GPIOx_Type *pGPIOx)
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
 * GPIO Read From Input Pin and Port
 */
uint8_t GPIO_ReadFromInputPin(GPIOx_Type *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;

	value = (uint8_t)(pGPIOx->IDR >> PinNumber & 0x00000001);

	return value;
}

uint8_t GPIO_ReadFromInputPort(GPIOx_Type *pGPIOx)
{
	uint16_t value;

	value = (uint16_t)(pGPIOx->IDR);

	return value;
}

/*
 * GPIO Write to Output Pin and Port
 */
void GPIO_WriteToOutputPin(GPIOx_Type *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

void GPIO_WriteToOutputPort(GPIOx_Type *pGPIOx, uint8_t Value)
{
	pGPIOx->ODR |= Value;
}

void GPIO_ToggleOutputPin(GPIOx_Type *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}
/*
 * GPIO Interrupt Configuration
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDis)
{

}

void GPIO_IRQHandling(uint8_t PinNumber)
{

}
