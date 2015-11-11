 /**
  *
  * \file main.c
  */

/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"
#include "macro_types.h"
#include "main.h"
#include "stm32f4_uart.h"
#include "stm32f4_sys.h"
#include "appli.h"
#include "stm32f4_timer.h"
#include "../../demo_touchscreen.h"
#include "../Vue/Menu_Principal_GUI.h"
#include "../Vue/Menu_SMS_GUI.h"
#include "../Vue/Saisie_message_maj_GUI.h"
#include "../Vue/Saisie_message_min_GUI.h"
#include "../../1010/Vue/Jeu_1010_GUI.h"
#include "../../TicTacToe/Vue/Jeu_TicTacToe_GUI.h"

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program.
  * @func int main(void)
  * @param  None
  * @retval None
  */
int main(void)
{
//	asm_main();
	HAL_Init();
	SYS_init();			//initialisation du systeme (horloge...)
	APPLI_init();
	NVIC_EnableIRQ(EXTI0_IRQn);
	//TIMER2_run_1ms();
	STM32f4_Discovery_LCD_Init();
	TS_Init();
	bool_e test = FALSE;
	uint16_t x=0,y=0;
	while(test == FALSE)test = TS_Get_Touch(&x,&y);
	while (1){
		int image = 8;
		switch(image){
		case 1:
			test_dessin_menu_principal();
			break;
		case 2:
			test_dessin_1010();
			break;
		case 3:
			test_dessin_TicTacToe();
			break;
		case 4:
			test_dessin_menu_sms();
			break;
		case 5:
			test_dessin_saisie_message_maj();
			break;
		case 6:
			test_dessin_saisie_message_min();
			break;
		case 7:
			jeu_lancer_TicTacToe();
			break;
		case 8:
			test_dessin_menu_principal();
			test_dessin_1010();
			test_dessin_TicTacToe();
			test_dessin_menu_sms();
			test_dessin_saisie_message_maj();
			test_dessin_saisie_message_min();
			break;
		default :
			while(TS_Calibration(test,CALIBRATION_MODE_JUST_CALIBRATE)!=TRUE);
			while(1)LCD_Clear(LCD_COLOR_YELLOW);
			break;
		}
	}
}





