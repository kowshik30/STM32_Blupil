/**********************************************************************************************
 * 																							  *
 * 					LED BLINKING PROGRAM FOR STM32F103C8T6 BLUEPILL BOARD 					  *
 *																							  *
 **********************************************************************************************/

#include <stdint.h>

/*Blinke the Port C -->13 */

/*......Step 1: Enable the PORT C Clock Base Address of PORT C is 0x4001 1000......*/
#define GPIOC_BASEADDR  (uint32_t)0x40011000
#define RCC_BASEADDR	(uint32_t)0x40021000

/*We have Port C located in APB2 Bus need to enable the clock via RCC*/

#define RCC_APB2ENR		(RCC_BASEADDR+0x18)   //Address of RCC APB2 Enable register
#define GPIOC_CRH		(GPIOC_BASEADDR+0x04) //Address of RCC Configuration High Register

#define GPIOC_ODR		(GPIOC_BASEADDR+0x0C)  // Address of Output data register

volatile uint32_t *pRCC_APB2ENR = 	(uint32_t*)RCC_APB2ENR;
volatile uint32_t *pGPIOC_CRH   = 	(uint32_t*)GPIOC_CRH;
volatile uint32_t *pGPIOC_BSRR  = 	(uint32_t*)GPIOC_BSRR;
volatile uint32_t *pGPIOC_ODR   = 	(uint32_t*)GPIOC_ODR;
//volatile uint32_t *ppGPIOC_ODR   = 	(uint32_t*)GPIOC_ODR;


int main(void)
{
	*pRCC_APB2ENR |= (1<<4);  //To set the PORT C clock in the RCC register
	*pGPIOC_CRH	  |=(1<<20);


while(1)
{
	*pGPIOC_ODR   |=(1<<13);
	for(int i=0;i<=500000;i++);
	*pGPIOC_ODR   &=~(1<<13);
	for(int i=0;i<=500000;i++);
}

}
