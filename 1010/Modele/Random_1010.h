
/** 
 * \file Random_1010.h
 * \brief Permet de recuperer un nombre aléatoire.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(RANDOM_1010_H)
#define RANDOM_1010_H


#ifdef __cplusplus
extern "C" {
#endif
    
    #include <stdlib.h>
    #include <stdint.h>
    #include "Bool_1010.h"
    //#include "stm32f4xx_hal.h"
    #define UINT16_DIVISE_2 32768
    
    /**
     * \fn int random_get_piece_1010()
     * \brief Retourne un numero de piece aléatoire entre 0 et 6.
     */
    int random_get_piece_1010();
    
#ifdef __cplusplus
}
#endif


#endif /*!defined(RANDOM_1010_H)*/
