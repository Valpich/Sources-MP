
/** 
 * \file controleur_TicTacToe_Tactile.h
 * \brief Defini le comportement de la partie controleur.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(controleur_TICTACTOE_TACTILE_H)
#define controleur_TICTACTOE_TACTILE_H


#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <setjmp.h>
#include "../Modele/Position_TicTacToe.h"
#include "../Modele/Type_TicTacToe.h"
#include "../Modele/Bool_TicTacToe.h"
#include "../Modele/Panneau_TicTacToe.h"
#include "../Jeu_TicTacToe.h"
#include "../Modele/Random_TicTacToe.h"

/**
 * \fn Position_TicTacToe choisir_position_TicTacToe()
 * \brief Retourne la position choisie par l'utilisateur si valide.
 * \return La position choisie.
 */
Position_TicTacToe choisir_position_TicTacToe();

/**
 * \fn Type_TicTacToe choisir_type_pion_TicTacToe()
 * \brief Retourne le type de pion choisi aleatoirement.
 * \return Le type choisi.
 */
Type_TicTacToe choisir_type_pion_TicTacToe();

/**
 * \fn void choisir_joueur_TicTacToe()
 * \brief Permet de choisir aleatoirement le premier joueur.
 */
void choisir_joueur_TicTacToe();

/**
 * \fn void choisir_quitter_jeu_TicTacToe()
 * \brief Permet de quitter le jeu en plein milieu.
 */
void choisir_quitter_jeu_TicTacToe();

#ifdef __cplusplus
}
#endif


#endif /*!defined(controleur_TICTACTOE_TACTILE_H)*/

