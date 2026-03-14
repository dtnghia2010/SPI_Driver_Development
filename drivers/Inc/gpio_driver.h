/*
 * gpio_driver.h
 *
 *  Created on: Dec 16, 2025
 *      Author: DELL
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include <stm32f429xx.h>




/*
 * This is a Configuration structure for a GPIO pin
 */
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdCtrl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltMode;
} GPIOx_Cfg_t;							/*<@GPIO_PIN_CONFIGURATION>*/


/*
 * This is a Handle structure for a GPIO pin
 */
typedef struct
{
	// Pointer to hold the based address of the GPIO peripheral
	GPIOx_Type *pGPIOx;

	GPIOx_Cfg_t GPIO_PinCFG;
} GPIO_Handle_t;

/**
 * @GPIO_PIN_CONFIGURATION
 *
 */


/**
 * GPIO pin possible mode
 */
#define GPIO_MODE_INPUT		0
#define GPIO_MODE_OUTPUT	1
#define GPIO_MODE_ALFN		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_IT_FT		4
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RFT	6

/**
 * GPIO port output type
 */
#define GPIO_OUTPUT_PP		0
#define GPIO_OUTPUT_OP		1


/**
 * GPIO port output speed register
 */
#define GPIO_OUTPUT_LSPEED	0
#define GPIO_OUTPUT_MSPEED	1
#define GPIO_OUTPUT_HSPEED	2
#define GPIO_OUTPUT_VHSPEED	3

/**
 * GPIO port pull-up/pull-down register
 */
#define GPIO_NO_PULL		0
#define GPIO_PULL_UP		1
#define	GPIO_PULL_DOWN		2

/**
 * GPIO pin number
 */

#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15



/***********************************************************************************
 * 							APIs supported by this driver
 * 			For more information about the APIs check the function definitions
 ************************************************************************************/

/*
 * GPIO Clock Control
 */
void GPIO_PclkCtrl(GPIOx_Type* pGPIOx, uint8_t EnorDis);


/*
 * GPIO Initialization and De-initialization
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);

void GPIO_DeInint(GPIOx_Type *pGPIOx);

/*
 * GPIO Read From Input Pin and Port
 */
uint8_t GPIO_ReadFromInputPin(GPIOx_Type *pGPIOx, uint8_t PinNumber);

uint16_t GPIO_ReadFromInputPort(GPIOx_Type *pGPIOx);

/*
 * GPIO Write to Output Pin and Port
 */
void GPIO_WriteToOutputPin(GPIOx_Type *pGPIOx, uint8_t PinNumber, uint8_t Value);

void GPIO_WriteToOutputPort(GPIOx_Type *pGPIOx, uint8_t Value);

void GPIO_ToggleOutputPin(GPIOx_Type *pGPIOx, uint8_t PinNumber);

/*
 * GPIO Interrupt Configuration
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDis);

void GPIO_IRQHandling(uint8_t PinNumber);


#endif /* GPIO_DRIVER_H_ */
