/*
 * appli.h
 *
 *  Created on: 1 avr. 2015
 *      Author: Nirgal
 */

#ifndef APPLI_H_
#define APPLI_H_
#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "stm32f4_gpio.h"
#include "stm32f4_uart.h"
#include "stm32f4_timer.h"
#include "stm32f4_sys.h"
#include "macro_types.h"
#include "stm32f4_accelerometer.h"
#include "stm32f4_lcd.h"

#define GREEN_LED	GPIOD, GPIO_PIN_12
#define ORANGE_LED	GPIOD, GPIO_PIN_13
#define RED_LED		GPIOD, GPIO_PIN_14
#define BLUE_LED	GPIOD, GPIO_PIN_15
#define BLUE_BUTTON	GPIOA, GPIO_PIN_0

static volatile bool_e count; //Si count est mis aÌ€ TRUE, le timer increÌ�mentera t
static volatile bool_e flag_new_value; //pour informer la taÌ‚che de fond
RNG_HandleTypeDef RNG_HandleStructure;

/*
 * @brief Initialisation de notre application, et des p�riph�riques qu'elle utilise.
 * @pre : cette fonction doit �tre appel�e pr�alablement � tout autre appel de fonction de cette classe.
 */
void APPLI_init(void);

/*
 * @brief Boucle de t�che de fond de l'application
 * @pre : doit �tre appel�e r�guli�rement.
 */
void APPLI_process_main(void);

/*
 * @brief Routine d'it de l'application.
 * @pre : cette fonction doit �tre appel�e toutes les ms.
 */
void APPLI_process_1ms(void);

void accelero(void);

#endif /* APPLI_H_ */
