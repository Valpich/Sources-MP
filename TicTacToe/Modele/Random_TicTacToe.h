
/** 
 * \file Random_TicTacToe.h
 * \brief Permet de recuperer un nombre aléatoire.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(RANDOM_TICTACTOE_H)
#define RANDOM_TICTACTOE_H


#ifdef __cplusplus
extern "C" {
#endif
    
    #include <stdlib.h>
    #include <stdint.h>
    #include "Bool_TicTacToe.h"
    #include "stm32f4xx_hal.h"
    #define UINT16_DIVISE_2 32768
    
    /**
     * \fn Bool_TicTacToe random_get_bool_TicTacToe()
     * \brief Retourne un booleen aléatoire.
     */
    Bool_TicTacToe random_get_bool_TicTacToe();
    
    
#ifdef __cplusplus
}
#endif


#endif /*!defined(RANDOM_TICTACTOE_H)*/
