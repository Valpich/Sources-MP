
/** 
 * \file controleur_1010.h
 * \brief Defini le comportement de la partie controleur.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(controleur_1010_H)
#define controleur_1010_H


#ifdef __cplusplus
extern "C" {
#endif

#include "../../1010/Modele/Piece_1010.h"
#include "../../1010/Jeu_1010.h"
#include "../../demo_touchscreen.h"

/**
 * \fn void choisir_position_1010(Piece_1010 piece)
 * \param piece La piece a placer.
 */
void choisir_position_1010(Piece_1010 piece);

/**
 * \fn void choisir_piece_1010()
 * \return La a piece choisie.
 */
int choisir_piece_1010();

/**
 * \fn void choisir_quitter_jeu_1010()
 * \brief Permet de quitter le jeu en plein milieu.
 */
void choisir_quitter_jeu_1010();

#ifdef __cplusplus
}
#endif


#endif /*!defined(controleur_1010_H)*/

