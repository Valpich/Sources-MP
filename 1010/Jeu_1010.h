
/** 
 * \file Jeu_1010.h
 * \brief Permet de jouer au jeu, possède le point d'entré du programme avec la méthode main.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(JEU_1010_H)
#define JEU_1010_H


#ifdef __cplusplus
extern "C" {
#endif

#include <setjmp.h>
#include "../../1010/Vue/Jeu_1010_GUI.h"
#include "Modele/Panneau_1010.h"
#include "controleur/controleur_1010.h"

/**
 * \var jmp_buf buf_1010
 * \brief Permet d'indiquer à quel moment revenir lors du longjump du controleur.
 */
jmp_buf buf_1010;

/**
 * \var Bool_1010 m_exit_1010
 * \brief Booléen indiquant qu'il faut terminer le jeu de façon instannée si TRUE.
 */
Bool_1010 m_exit_1010;

/**
 * \fn int jeu_lancer_1010()
 * \brief Permet de lancer le jeu, peut être appelé sans la méthode main par un autre programme.
 * \return La valeur du jeu, indique une erreur si différent de 0.
 */
int jeu_lancer_1010();

/**
 * \fn int jeu_1010_jouer()
 * \brief Permet de jouer au jeu.
 * \return La valeur du jeu, indique une erreur si différent de 0.
 */
int jeu_1010_jouer();

/**
 * \fn Bool_1010 test_fin_de_jeu(Piece_1010 piece_1, Piece_1010 piece_2, Piece_1010 piece_3, Bool_1010 * test)
 * \brief Test si le jeu est fini ou non.
 * \param piece_1 la premiere piece.
 * \param piece_2 la seconde piece.
 * \param piece_3 la troisieme piece.
 * \param test le tableau contenant les pieces disponibles.
 * \return Vrai si le jeu est sinon faux.
 */
Bool_1010 test_fin_de_jeu(Piece_1010 piece_1, Piece_1010 piece_2, Piece_1010 piece_3, Bool_1010 * test);

/**
 * \fn Bool_1010 test_position_possible(Piece_1010 piece_1, Piece_1010 piece_2, Piece_1010 piece_3,int numero_piece)
 * \brief Permet de jouer au jeu.
 * \param piece_1 la premiere piece.
 * \param piece_2 la seconde piece.
 * \param piece_3 la troisieme piece.
 * \param numero_piece le numero de la piece � tester.
 * \return La valeur du jeu, indique une erreur si différent de 0.
 */
Bool_1010 test_position_possible(Piece_1010 piece_1, Piece_1010 piece_2, Piece_1010 piece_3,int numero_piece);

#ifdef __cplusplus
}
#endif


#endif /*!defined(JEU_1010_H)*/

