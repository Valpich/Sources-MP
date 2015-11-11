/*
 * appli.c
 *
 *  Created on: 08/2015
 *      Author: S. Poiraud
 */
#include "appli.h"
#include "stm32f4xx_hal.h"
#include "stm32f4_gpio.h"
#include "stm32f4_uart.h"
#include "stm32f4_timer.h"
#include "stm32f4_sys.h"
#include "macro_types.h"

#define GREEN_LED	GPIOD, GPIO_PIN_12
#define ORANGE_LED	GPIOD, GPIO_PIN_13
#define RED_LED		GPIOD, GPIO_PIN_14
#define BLUE_LED	GPIOD, GPIO_PIN_15
#define BLUE_BUTTON	GPIOA, GPIO_PIN_0

static volatile uint32_t t;
static volatile bool_e count; //Si count est mis aÌ€ TRUE, le timer increÌ�mentera t
static volatile bool_e flag_new_value; //pour informer la taÌ‚che de fond

//////////////////////////////////////

/*
 * Initialisation de notre application, et des pÃ©riphÃ©riques qu'elle utilise
 */
void APPLI_init(void)
{
	GPIO_Configure();	//Configuration des broches d'entree-sortie.

	//UART_init(6,UART_RECEIVE_ON_MAIN);	//Initialisation de l'USART6 (PC6=Tx, PC7=Rx, 115200 bauds/sec)
	//SYS_set_std_usart(USART6,USART6,USART6);

	//Configuration du port du bouton bleu en entrÃ©e
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.Pin = GPIO_PIN_0;
	GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING_FALLING;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure.Alternate = 0;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/*
 * @brief Boucle de tÃ¢che de fond de l'application
 * @pre : doit Ãªtre appelÃ©e rÃ©guliÃ¨rement.
 */
void APPLI_process_main(void)
{
	while(1){
	}
}

void EXTI0_IRQHandler(void) {
	if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET){ //Normalement forceÌ�ment vrai
		if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET){
			__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0); //On acquitte l'interruption.
		}
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)) { //Front montant
             t = 0;
             count = TRUE;
		}else { //Front descedant
             flag_new_value = TRUE;
             count = FALSE;
		}
	}
}
//Front montant
