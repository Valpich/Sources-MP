/****************************************************
 *  Random_TicTacToe.c
 *  Created on: oct.-2015
 *  Implementation of the Class Random
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Random_TicTacToe.h"

Bool_TicTacToe random_get_bool_TicTacToe(){
    srand((uint16_t)SysTick->VAL);
    if((uint16_t)rand() >= UINT16_DIVISE_2)return TRUE_TICTACTOE;
    return FALSE_TICTACTOE;
}

//CODE DE TEST STM32
//random_get_bool_TicTacToe()
/*
while(1){
    int allumeBlue = 0;
    int allumeOrange = 0;
    int allumeGreen = 0;
    int allumeRed = 0;
    switch(random_get_bool_TicTacToe()){
        case TRUE:
            allumeRed = 1;
            allumeGreen = 1;
            break;
        case FALSE:
            allumeBlue = 1;
            allumeOrange = 1;
            break;
        default:
            allumeBlue = 0;
            allumeOrange = 0;
            allumeGreen = 0;
            allumeRed = 0;
            break;
    }
    for(i=0;i<100000;i++){
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
