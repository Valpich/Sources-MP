/**
 *
 * \file main.c
 */

/* Includes ------------------------------------------------------------------*/

#include "main.h"

//#define DEBUG_ON

/* Private functions ---------------------------------------------------------*/
/**
 * @brief  Main program.
 * @func int main(void)
 * @param  None
 * @retval None
 */
int main(void){
	HAL_Init();
	SYS_init();
	APPLI_init();
	UART_init(6,UART_RECEIVE_ON_MAIN);	//Initialisation de l'USART6 (PC6=Tx, PC7=Rx, 115200 bauds/sec)
	SYS_set_std_usart(USART6,USART6,USART6);
	NVIC_EnableIRQ(EXTI0_IRQn);
	TIMER2_run_1ms();
	STM32f4_Discovery_LCD_Init();
	TS_Init();
	while (1){
		tache_principale();
	}
}

void tache_principale(){
	typedef enum{
		MENU_PRINCIPAL = 0,
		APPLI_SMS,
		APPLI_TICTACTOE,
		APPLI_1010
	}state_e;
	bool_e test = FALSE;
	static state_e etat = MENU_PRINCIPAL;
	static state_e etat_precedent = -1;
	uint16_t x = 0,y = 0;
	bool_e appuye = FALSE;
#ifdef DEBUG_ON
	static char mail[] = "zetafr@gmail.com";
	static char objet[] = "Objet mail";
	static char message[] = "Message mail";
	etat =-1;
#endif
	switch(etat){
	case MENU_PRINCIPAL:
		if(etat_precedent != etat){
			dessin_menu_principal();
		}
		appuye = TS_Get_Touch(&x, &y);
		if(appuye == TRUE)etat = appuye_menu(x, y);
		etat_precedent = MENU_PRINCIPAL;
		break;
	case APPLI_SMS:
#ifdef DEBUG_ON
		SMS_envoyer(mail,objet,message);
#endif
		appli_SMS_lancer();
		etat_precedent = APPLI_SMS;
		etat = MENU_PRINCIPAL; //Fin de l'appli
		break;
	case APPLI_TICTACTOE:
		jeu_lancer_TicTacToe();
		etat_precedent = APPLI_TICTACTOE;
		etat = MENU_PRINCIPAL; //Fin de l'appli
		break;
	case APPLI_1010:
		jeu_lancer_1010();
		etat_precedent = APPLI_1010;
		etat = MENU_PRINCIPAL; //Fin de l'appli
		break;
	default :
		etat_precedent = -1;
		while(TS_Calibration(test,CALIBRATION_MODE_CALIBRATE_AND_SHOW_VALUE)!=TRUE);
		break;
	}
}


