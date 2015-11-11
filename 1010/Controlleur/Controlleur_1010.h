
/** 
 * \file Controlleur_1010.h
 * \brief Defini le comportement de la partie controlleur.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(CONTROLLEUR_1010_H)
#define CONTROLLEUR_1010_H


#ifdef __cplusplus
extern "C" {
#endif

    #include "../Modele/Piece_1010.h"

    /** 
     * \fn Piece choisir_piece_1010()
     * \brief Retourne une piece choisie par l'utilisateur.
     * \return Une nouvelle piece.
     */
    Piece_1010 choisir_piece_1010();
    
    /**
     * \fn int choisir_x_1010()
     * \brief Retourne un entier choisi par l'utilisateur.
     * \return La valeur choisie pour x par l'utilisateur.
     * Possede également une focntion d'affichage terminal.
     */
    int  choisir_x_1010();
    
    /**
     * \fn int choisir_y_1010()
     * \brief Retourne un entier choisi par l'utilisateur.
     * \return La valeur choisie pour y par l'utilisateur.
     * Possede également une focntion d'affichage terminal.
     */
    int  choisir_y_1010();
    
#ifdef __cplusplus
}
#endif


#endif /*!defined(CONTROLLEUR_1010_H)*/
 