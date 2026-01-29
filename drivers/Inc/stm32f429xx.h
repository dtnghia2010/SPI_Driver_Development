/*
 * stm32f429xx.h
 *
 *  Created on: Dec 16, 2025
 *      Author: DELL
 */

#ifndef INC_STM32F429XX_H_
#define INC_STM32F429XX_H_

#include <stm32f429xx.h>
#include <stdint.h>
#define __vo 					volatile

/*
 *	Macros for reset register GPIOx
 */

#define GPIOA_REG_RESET()		do {(RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0));} while(0)
#define GPIOB_REG_RESET()		do {(RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1));} while(0)
#define GPIOC_REG_RESET()		do {(RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2));} while(0)
#define GPIOD_REG_RESET()		do {(RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3));} while(0)
#define GPIOE_REG_RESET()		do {(RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4));} while(0)
#define GPIOF_REG_RESET()		do {(RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5));} while(0)
#define GPIOG_REG_RESET()		do {(RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6));} while(0)
#define GPIOH_REG_RESET()		do {(RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7));} while(0)
#define GPIOI_REG_RESET()		do {(RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8));} while(0)


/*
 *	Macros for reset register SPIx
 */

#define SPI1_REG_RESET()		do {(RCC->APB2RSTR |= (1 << 12)); (RCC->APB2RSTR &= ~(1 << 12));} while(0)
#define SPI2_REG_RESET()		do {(RCC->APB1RSTR |= (1 << 14)); (RCC->APB1RSTR &= ~(1 << 14));} while(0)
#define SPI3_REG_RESET()		do {(RCC->APB1RSTR |= (1 << 15)); (RCC->APB1RSTR &= ~(1 << 15));} while(0)
#define SPI4_REG_RESET()		do {(RCC->APB2RSTR |= (1 << 13)); (RCC->APB2RSTR &= ~(1 << 13));} while(0)
#define SPI5_REG_RESET()		do {(RCC->APB2RSTR |= (1 << 20)); (RCC->APB2RSTR &= ~(1 << 20));} while(0)
#define SPI6_REG_RESET()		do {(RCC->APB2RSTR |= (1 << 21)); (RCC->APB2RSTR &= ~(1 << 21));} while(0)


/*
 *	macros for all the possible priority levels
 */

#define NVIC_IRQ_PRIO0	0
#define NVIC_IRQ_PRIO15	15


#define ENABLE 					1
#define DISABLE 				0
#define SET 					ENABLE
#define RESET					DISABLE
#define FLAG_SET				ENABLE
#define FLAG_RESET				DISABLE
#define GPIO_PIN_SET			SET
#define GPIO_PIN_RESET			RESET
#define FLASH_BASEADDR			0x08000000U
#define SRAM1_BASEADDR			0x20000000U
#define SRAM2_BASEADDR			0x2001C000U
#define ROM						0x1FFF0000U
#define SRAM 					SRAM1_BASEADDR


/*
 * Bit position definitions for SPI_CR1
 */
#define SPI_CR1_CPHA_Pos           (0U)
#define SPI_CR1_CPOL_Pos           (1U)
#define SPI_CR1_MSTR_Pos           (2U)
#define SPI_CR1_BR_Pos             (3U)
#define SPI_CR1_SPE_Pos            (6U)
#define SPI_CR1_LSBFIRST_Pos       (7U)
#define SPI_CR1_SSI_Pos            (8U)
#define SPI_CR1_SSM_Pos            (9U)
#define SPI_CR1_RXONLY_Pos         (10U)
#define SPI_CR1_DFF_Pos            (11U)
#define SPI_CR1_CRCNEXT_Pos        (12U)
#define SPI_CR1_CRCEN_Pos          (13U)
#define SPI_CR1_BIDIOE_Pos         (14U)
#define SPI_CR1_BIDIMODE_Pos       (15U)

/*
 * Bit mask definitions for SPI_CR1
 */
#define SPI_CR1_CPHA_Msk           (0x1U)
#define SPI_CR1_CPOL_Msk           (0x1U)
#define SPI_CR1_MSTR_Msk           (0x1U)
#define SPI_CR1_BR_Msk             (0x7U)
#define SPI_CR1_SPE_Msk            (0x1U)
#define SPI_CR1_LSBFIRST_Msk       (0x1U)
#define SPI_CR1_SSI_Msk            (0x1U)
#define SPI_CR1_SSM_Msk            (0x1U)
#define SPI_CR1_RXONLY_Msk         (0x1U)
#define SPI_CR1_DFF_Msk            (0x1U)
#define SPI_CR1_CRCNEXT_Msk        (0x1U)
#define SPI_CR1_CRCEN_Msk          (0x1U)
#define SPI_CR1_BIDIOE_Msk         (0x1U)
#define SPI_CR1_BIDIMODE_Msk       (0x1U)

/* Bit position definitions for SPI_CR2 */
#define SPI_CR2_RXDMAEN_Pos        (0U)
#define SPI_CR2_TXDMAEN_Pos        (1U)
#define SPI_CR2_SSOE_Pos           (2U)
#define SPI_CR2_FRF_Pos            (4U)
#define SPI_CR2_ERRIE_Pos          (5U)
#define SPI_CR2_RXNEIE_Pos         (6U)
#define SPI_CR2_TXEIE_Pos          (7U)

/* Bit mask definitions for SPI_CR2 */
#define SPI_CR2_RXDMAEN_Msk        (0x1U << SPI_CR2_RXDMAEN_Pos)
#define SPI_CR2_TXDMAEN_Msk        (0x1U << SPI_CR2_TXDMAEN_Pos)
#define SPI_CR2_SSOE_Msk           (0x1U << SPI_CR2_SSOE_Pos)
#define SPI_CR2_FRF_Msk            (0x1U << SPI_CR2_FRF_Pos)
#define SPI_CR2_ERRIE_Msk          (0x1U << SPI_CR2_ERRIE_Pos)
#define SPI_CR2_RXNEIE_Msk         (0x1U << SPI_CR2_RXNEIE_Pos)
#define SPI_CR2_TXEIE_Msk          (0x1U << SPI_CR2_TXEIE_Pos)


/* Bit position definitions for SPI_SR */
#define SPI_SR_RXNE_Pos            (0U)   // Receive buffer not empty
#define SPI_SR_TXE_Pos             (1U)   // Transmit buffer empty
#define SPI_SR_CHSIDE_Pos          (2U)   // Channel side (I2S mode)
#define SPI_SR_UDR_Pos             (3U)   // Underrun flag
#define SPI_SR_CRCERR_Pos          (4U)   // CRC error flag
#define SPI_SR_MODF_Pos            (5U)   // Mode fault
#define SPI_SR_OVR_Pos             (6U)   // Overrun flag
#define SPI_SR_BSY_Pos             (7U)   // Busy flag
#define SPI_SR_FRE_Pos             (8U)   // Frame format error

/* Bit mask definitions for SPI_SR */
#define SPI_SR_RXNE_Msk            (0x1U << SPI_SR_RXNE_Pos)
#define SPI_SR_TXE_Msk             (0x1U << SPI_SR_TXE_Pos)
#define SPI_SR_CHSIDE_Msk          (0x1U << SPI_SR_CHSIDE_Pos)
#define SPI_SR_UDR_Msk             (0x1U << SPI_SR_UDR_Pos)
#define SPI_SR_CRCERR_Msk          (0x1U << SPI_SR_CRCERR_Pos)
#define SPI_SR_MODF_Msk            (0x1U << SPI_SR_MODF_Pos)
#define SPI_SR_OVR_Msk             (0x1U << SPI_SR_OVR_Pos)
#define SPI_SR_BSY_Msk             (0x1U << SPI_SR_BSY_Pos)
#define SPI_SR_FRE_Msk             (0x1U << SPI_SR_FRE_Pos)

/* SPI Flags */
#define SPI_RXNE_FLAG              SPI_SR_RXNE_Msk		 // Receive buffer not empty
#define SPI_TXE_FLAG               SPI_SR_TXE_Msk		 // Transmit buffer empty
#define SPI_CHSIDE_FLAG            SPI_SR_CHSIDE_Msk		 // Channel side (I2S mode)
#define SPI_UDR_FLAG               SPI_SR_UDR_Msk		 // Underrun flag
#define SPI_CRCERR_FLAG            SPI_SR_CRCERR_Msk		 // CRC error flag
#define SPI_MODF_FLAG              SPI_SR_MODF_Msk		 // Mode fault
#define SPI_OVR_FLAG               SPI_SR_OVR_Msk		 // Overrun flag
#define SPI_BSY_FLAG               SPI_SR_BSY_Msk		 // Busy flag
#define SPI_FRE_FLAG               SPI_SR_FRE_Msk		 // Frame format error

/*
 *
 * AHBx and APBx Bus Peripheral base addresses
 *
 */

#define PERIPH_BASEADDR			0x40000000U
#define APB1_BASEADDR			PERIPH_BASEADDR
#define APB2_BASEADDR			APB1_BASEADDR + 0x10000U
#define AHB1_BASEADDR			APB1_BASEADDR + 0x20000U
#define AHB2_BASEADDR			0x50000000U


/*
 *
 * Base addresses of peripherals which are connected to AHB1 bus
 *
 */

#define GPIOA_BASEADDR			(AHB1_BASEADDR + 0x0U)
#define GPIOB_BASEADDR			(AHB1_BASEADDR + 0x400U)
#define GPIOC_BASEADDR			(AHB1_BASEADDR + 0x800U)
#define GPIOD_BASEADDR			(AHB1_BASEADDR + 0xC00U)
#define GPIOE_BASEADDR			(AHB1_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR			(AHB1_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR			(AHB1_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR			(AHB1_BASEADDR + 0x1C00U)
#define GPIOI_BASEADDR			(AHB1_BASEADDR + 0x2000U)
#define RCC_BASEADDR			(AHB1_BASEADDR + 0x3800U)

/*
 *
 * Base addresses of peripherals which are connected to APB1 bus
 *
 */

#define SPI2_BASEADDR			(APB1_BASEADDR + 0x3800U)
#define SPI3_BASEADDR			(APB1_BASEADDR + 0x3C00U)
#define USART2_BASEADDR			(APB1_BASEADDR + 0x4400U)
#define USART3_BASEADDR			(APB1_BASEADDR + 0x4800U)
#define UART4_BASEADDR			(APB1_BASEADDR + 0x4C00U)
#define UART5_BASEADDR			(APB1_BASEADDR + 0x5000U)
#define I2C1_BASEADDR			(APB1_BASEADDR + 0x5400U)
#define I2C2_BASEADDR			(APB1_BASEADDR + 0x5800U)
#define I2C3_BASEADDR			(APB1_BASEADDR + 0x5C00U)


/*
 *
 * Base addresses of peripherals which are connected to APB2 bus
 *
 */

#define USART1_BASEADDR 		(APB2_BASEADDR + 0x1000U)
#define USART6_BASEADDR 		(APB2_BASEADDR + 0x1400U)
#define SPI1_BASEADDR			(APB2_BASEADDR + 0x3000U)
#define SPI4_BASEADDR			(APB2_BASEADDR + 0x3400U)
#define SYSCFG_BASEADDR 		(APB2_BASEADDR + 0x3800U)
#define EXTI_BASEADDR 			(APB2_BASEADDR + 0x3C00U)
#define SPI5_BASEADDR			(APB2_BASEADDR + 0x5000U)
#define SPI6_BASEADDR			(APB2_BASEADDR + 0x5400U)


/*
 *
 * Peripheral register definition structures SPI
 *
 */

typedef struct
{
	__vo uint32_t CR1;			// 0x0
	__vo uint32_t CR2;			// 0x4
	__vo uint32_t SR;			// 0x8
	__vo uint32_t DR;			// 0xC
	__vo uint32_t CRCPR;		// 0x10
	__vo uint32_t RXCRCR;		// 0x14
	__vo uint32_t TXCRCR;		// 0x18
	__vo uint32_t I2SCFGR;		// 0x1C
	__vo uint32_t I2SPR;		// 0x20
} SPIx_Type;


/*
 *
 *  Peripheral register definition structures GPIO
 *
 */

typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
} GPIOx_Type;

/*
 *
 *  Peripheral register definition structures RCC
 *
 */


typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	uint32_t 	  RESERVED0;

	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t 	  RESERVED1[2];

	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	uint32_t	  RESERVED2;

	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t	  RESERVED3[2];

	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	uint32_t	  RESERVED4;

	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	uint32_t	  RESERVED5[2];

	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t	  RESERVED6[2];

	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t SAICFGR;
	__vo uint32_t DCKCFGR;
} RCC_Type;


/*
 *
 *  Peripheral register definition structures EXTI
 *
 */


typedef struct
{
	__vo uint32_t IMR;			// 0x00
	__vo uint32_t EMR;			// 0x04
	__vo uint32_t RTSR;			// 0x08
	__vo uint32_t FTSR;			// 0x0C
	__vo uint32_t SWIER;		// 0x10
	__vo uint32_t PR;			// 0x14
} EXTI_Type;

#define GPIOA	((GPIOx_Type*) GPIOA_BASEADDR)
#define GPIOB	((GPIOx_Type*) GPIOB_BASEADDR)
#define GPIOC	((GPIOx_Type*) GPIOC_BASEADDR)
#define GPIOD	((GPIOx_Type*) GPIOD_BASEADDR)
#define GPIOE	((GPIOx_Type*) GPIOE_BASEADDR)
#define GPIOF	((GPIOx_Type*) GPIOF_BASEADDR)
#define GPIOG	((GPIOx_Type*) GPIOG_BASEADDR)
#define GPIOH	((GPIOx_Type*) GPIOH_BASEADDR)
#define GPIOI	((GPIOx_Type*) GPIOI_BASEADDR)
#define SPI1	((SPIx_Type*) SPI1_BASEADDR)
#define SPI2	((SPIx_Type*) SPI2_BASEADDR)
#define SPI3	((SPIx_Type*) SPI3_BASEADDR)
#define SPI4	((SPIx_Type*) SPI4_BASEADDR)
#define SPI5	((SPIx_Type*) SPI5_BASEADDR)
#define SPI6	((SPIx_Type*) SPI6_BASEADDR)
#define RCC		((RCC_Type*) RCC_BASEADDR)
#define EXTI	((EXTI_Type*) EXTI_BASEADDR)

/*
 * Clock enable Macros for GPIOx peripherals
 *
 */
#define GPIOA_PCLK_EN()		(RCC->AHB1ENR	|= (1 << 0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR	|= (1 << 2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR	|= (1 << 4))
#define GPIOF_PCLK_EN()		(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()		(RCC->AHB1ENR	|= (1 << 6))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()		(RCC->AHB1ENR |= (1 << 8))


/*
 * Clock enable macros for I2Cx peripherals
 *
 */

#define I2C1_PCLK_EN()		(RCC->APB1ENR |= (1 << 21))


/*
 * Clock enable macro for SPIx peripherals
 *
 */

#define SPI1_PCLK_EN()		(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()		(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()		(RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()		(RCC->APB2ENR |= (1 << 13))
#define SPI5_PCLK_EN()		(RCC->APB2ENR |= (1 << 20))
#define SPI6_PCLK_EN()		(RCC->APB2ENR |= (1 << 21))


/*
 * Clock disable Macros for GPIOx peripherals
 *
 */

#define GPIOA_PCLK_DI()		(RCC->AHB1ENR	&= ~(1 << 0))
#define GPIOB_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()		(RCC->AHB1ENR	&= ~(1 << 2))
#define GPIOD_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()		(RCC->AHB1ENR	&= ~(1 << 4))
#define GPIOF_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()		(RCC->AHB1ENR	&= ~(1 << 6))
#define GPIOH_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 8))

/*
 * clock disable macros for I2Cx peripherals
 *
 */

#define I2C1_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 21))


/*
 * clock disable macros for SPIx peripherals
 *
 */

#define SPI1_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 13))
#define SPI5_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 20))
#define SPI6_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 21))

/*
	IRQ number of STM32F429xMCU
*/

#define IRQ_NO_EXTI0		6
#define IRQ_NO_EXTI1		7
#define IRQ_NO_EXTI2		8
#define IRQ_NO_EXTI3		9
#define IRQ_NO_EXTI4		10
#define IRQ_NO_EXTI9_5		23
#define IRQ_NO_EXTI15_10	40




#include <gpio_driver.h>
#include <i2c_driver.h>
#include <spi_driver.h>
#include <uart_driver.h>


#endif /* INC_STM32F429XX_H_ */
