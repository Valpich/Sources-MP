/*
 * appli.c
 *
 *  Created on: 08/2015
 *      Author: S. Poiraud
 */
#include "appli.h"

//////////////////////////////////////
/*
 * Initialisation de notre application, et des pÃ©riphÃ©riques qu'elle utilise
 */
void APPLI_init(void){
	GPIO_Configure();	//Configuration des broches d'entree-sortie.
	BSP_GPIO_PinCfg(GREEN_LED, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FAST, 0);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.Pin = GPIO_PIN_0;
	GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING_FALLING;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure.Alternate = 0;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

}

void EXTI0_IRQHandler(void){
	volatile static int lock = 0;
	if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET){ //Normalement forceÌ�ment vrai
		__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0); //On acquitte l'interruption.
		if(lock == 1)lock = 0;
		else lock = 1;
	}
	if(lock == 1){
	}
}


//Front montant
/*
void accelero(void){
	BSP_ACCELERO_Init();
	int16_t pDataXYZ[3];
	int chute = pDataXYZ[2];
	BSP_ACCELERO_GetXYZ(pDataXYZ);
	static int allumeRed = 0;
	static int allumeBlue = 0;
	static int allumeGreen = 0;
	static int allumeOrange = 0;
	if(allumeRed == 1)HAL_GPIO_WritePin(RED_LED, 1);
	else HAL_GPIO_WritePin(RED_LED, 0);
	if(allumeBlue == 1)HAL_GPIO_WritePin(BLUE_LED, 1);
	else HAL_GPIO_WritePin(BLUE_LED, 0);
	if(allumeGreen == 1)HAL_GPIO_WritePin(GREEN_LED, 1);
	else HAL_GPIO_WritePin(GREEN_LED, 0);
	if(allumeOrange == 1)HAL_GPIO_WritePin(ORANGE_LED, 1);
	else HAL_GPIO_WritePin(ORANGE_LED, 0);
	if(pDataXYZ[0]>100){
			allumeRed = 1;
	}else{
			allumeRed = 0;
	}
	if(pDataXYZ[0]<-100){
			allumeGreen = 1;
	}else{
			allumeGreen = 0;
	}
	if(pDataXYZ[1]>100){
			allumeOrange = 1;
	}else{
			allumeOrange = 0;
	}
	if(pDataXYZ[1]<-100){
			allumeBlue = 1;
	}else{
			allumeBlue = 0;
	}
	if(pDataXYZ[0]<=100&&pDataXYZ[0]>=-100&&pDataXYZ[1]<=100&&pDataXYZ[1]>=-100){
			allumeBlue = 0;
			allumeOrange = 0;
			allumeGreen = 0;
			allumeRed = 0;
	}
	if((chute-pDataXYZ[2]>=300)||(chute-pDataXYZ[2]<=-300)){
			allumeBlue = 1;
			allumeOrange = 1;
			allumeGreen = 1;
			allumeRed = 1;
	}
}*/

/*
void state_machine(){
	static int allumeRed = 0;
	static int camera_trigger = 0;
	if(allumeRed == 1)HAL_GPIO_WritePin(RED_LED, 1);
	else HAL_GPIO_WritePin(RED_LED, 0);
	typedef enum{
		INIT,
		WAIT_BUTTON,
		BLINK_500MS,
		BLINK_100MS,
		RUN_TRIGGER,
		WAIT_10MS
	}state_e;
	static state_e etat= INIT;
	switch (etat){
		case INIT :
			allumeRed = 0;
			camera_trigger = 0;
			TIMER2_run_1ms();
			etat = WAIT_BUTTON;
			break;
		case WAIT_BUTTON:
			if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == TRUE){
				t=3000;
				test = FALSE;
				etat = BLINK_500MS;
			}
			break;
		case BLINK_500MS:
			allumeRed  = (t/500)%2;
			if(!t){
				t = 2000;
				etat = BLINK_100MS;
			}
			break;
		case BLINK_100MS:
			allumeRed  = (t/100)%2;
			if(!t)etat = RUN_TRIGGER;
			break;
		case RUN_TRIGGER:
			camera_trigger = 1;
			t=10;
			etat = WAIT_10MS;
			break;
		case WAIT_10MS:
			if(!t){
				camera_trigger = 0;
				etat = WAIT_BUTTON;
			}
			break;
		default:
			etat = INIT;
			break;
	}
}
 */
