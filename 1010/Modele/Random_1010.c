/****************************************************
 *  Random_1010.c
 *  Created on: oct.-2015
 *  Implementation of the Class Random
 *  Original author: Romain Hamon Valentin Pichavant
 ****************************************************/

#include "Random_1010.h"

int random_get_piece_1010(){
	srand((uint16_t)SysTick->VAL);
	if((uint16_t)rand() <= UINT16_DIVISE_2/12){
		return 0;
	}
	if((uint16_t)rand() <= 2*UINT16_DIVISE_2/12){
		return 1;
	}
	if((uint16_t)rand() <= 3*UINT16_DIVISE_2/12){
		return 2;
	}
	if((uint16_t)rand() <= 4*UINT16_DIVISE_2/12){
		return 3;
	}
	if((uint16_t)rand() <= 5*UINT16_DIVISE_2/12){
		return 4;
	}
	if((uint16_t)rand() <= 6*UINT16_DIVISE_2/12){
		return 5;
	}
	if((uint16_t)rand() <= 7*UINT16_DIVISE_2/12){
		return 6;
	}
	if((uint16_t)rand() <= 8*UINT16_DIVISE_2/12){
		return 7;
	}
	if((uint16_t)rand() <= 9*UINT16_DIVISE_2/12){
		return 8;
	}
	if((uint16_t)rand() <= 10*UINT16_DIVISE_2/12){
		return 9;
	}
	if((uint16_t)rand() <= 11*UINT16_DIVISE_2/12){
		return 10;
	}
	if((uint16_t)rand() <= UINT16_DIVISE_2){
		return 11;
	}
	return 0;
}


//CODE DE TEST STM 32 :
//random_get_piece_1010();
/*
 while(1){
    int allumeRed = 0;
    int allumeBlue = 0;
    int allumeGreen = 0;
    int allumeOrange = 0;
    switch(random_get_piece_1010()){
        case 0:
            allumeRed = 1;
            break;
        case 1:
            allumeBlue = 1;
            break;
        case 2:
            allumeGreen = 1;
            break;
        case 3:
            allumeOrange = 1;
            break;
        case 4:
            allumeRed = 1;
            allumeGreen = 1;
            break;
        case 5:
            allumeBlue = 1;
            allumeOrange = 1;
            break;
        case 6:
            allumeBlue = 1;
            allumeOrange = 1;
            allumeGreen = 1;
            allumeRed = 1;
            break;
        default:
            allumeBlue = 0;
            allumeOrange = 0;
            allumeGreen = 0;
            allumeRed = 0;
            break;
    }
    for(i=0;i<1000000;i++){
        if(allumeRed == 1)HAL_GPIO_WritePin(RED_LED, 1);
        else HAL_GPIO_WritePin(RED_LED, 0);
        if(allumeBlue == 1)HAL_GPIO_WritePin(BLUE_LED, 1);
        else HAL_GPIO_WritePin(BLUE_LED, 0);
        if(allumeGreen == 1)HAL_GPIO_WritePin(GREEN_LED, 1);
        else HAL_GPIO_WritePin(GREEN_LED, 0);
        if(allumeOrange == 1)HAL_GPIO_WritePin(ORANGE_LED, 1);
        else HAL_GPIO_WritePin(ORANGE_LED, 0);
    }
}
 */
